using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics.Tracing;
using UnityEngine;

public class Gris : Enemy
{

    public Signal alarm;
    public Signal falseAlarm;
    public Rigidbody2D myRigidbody;
    public Transform blanco;
    //Pedir al server
    public float range;
    public float chaseSpeed;
    public float regularSpeed;

    public float attackRange;
    public Transform homePosition;
    public Animator animador;


    //Pedir al server
    public string[] defa;
    public string[] attack = { };
    public Stack<Vector2> backtrack = new Stack<Vector2>();
    public int counter = 0;
    public int attCounter = 0;
    public int btCounter = 0;
    public Vector2 facing;
    public bool alarmed;
    private bool raised;
    public bool attacking;
    public string statResp;
    public string defResp;
    public string atkResp;
    public string bckResponse;
    public bool isSafe;
    public int backtrackCiclo = 0;
    public int alarmCiclo = 0;
    // Start is called before the first frame update
    void Start()
    {
        statResp = client.instance.send("E" + ID + "S");
        regularSpeed = float.Parse(statResp.Split(';')[2]);
        range = float.Parse(statResp.Split(';')[1]);
        //range = 4;
        chaseSpeed = float.Parse(statResp.Split(';')[0]);
        defResp = client.instance.send("E" + ID + "D");
        defa = defResp.Split(';');
        currentState = EnemyState.walk;
        myRigidbody = GetComponent<Rigidbody2D>();
        blanco = GameObject.FindWithTag("Player").transform;
        animador = GetComponent<Animator>();
    }

    // Update is called once per frame
    void FixedUpdate()
    {

        if (!isSafe)
        {
            CheckDistance();
            if (currentState == EnemyState.follow)
            {
                //Debug.Log("Chasing");
                Chase();
            }
            else if (currentState == EnemyState.backtrack)
            {
                Debug.Log("backtracking");
                Backtrack();
            }
            else if (currentState == EnemyState.walk)
            {
                Debug.Log("walking");
                Walk();
            }
            else if (currentState == EnemyState.attack)
            {
                
                Attack();
            }
        }
        else
        {
            
                //Debug.Log("Walking else");
                Walk();
            
            
        }

    }
    public void CheckDistance()
    {
        float xValue = (blanco.position.x - transform.position.x) / (Math.Abs(blanco.position.x - transform.position.x));
        float yValue = (blanco.position.y - transform.position.y) / (Math.Abs(blanco.position.y - transform.position.y));
        if (Vector3.Distance(blanco.position, transform.position) <= range
            && ((xValue == 1 && facing == Vector2.right) || (yValue == 1 && facing == Vector2.up)
            || (yValue == -1 && facing == Vector2.down) || (xValue == -1 && facing == Vector2.left)))

        {
            if (currentState == EnemyState.idle || currentState == EnemyState.walk || currentState == EnemyState.backtrack
                && currentState != EnemyState.stagger)
            {
                if (!alarmed)
                { 
                    alarmed = true; 
                    client.instance.send("E" + ID + "V");
                    client.instance.send("E" + ID + "P" + (int)transform.position.x + "," + (int)transform.position.y);
                }

                ChangeState(EnemyState.follow);
                Debug.Log("Follow state");

                if (alarmCiclo > 40)
                {
                    alarm.Raise();
                    alarmCiclo = 0;
                }
                alarmCiclo++;
            }

        }
        else
        {
            if (currentState != EnemyState.attack) {
                falseAlarm.Raise();
                alarmCiclo = 0;
                if (backtrackCiclo > 200)
                {
                    backtrackCiclo = 0;
                    client.instance.send("E" + ID + "B");
                }
                alarmed = false;
                attacking = false;
                
            }
            backtrackCiclo++;
        }

    }
    public virtual void Attack()
    {
        Debug.Log("Gris atacando");
        //ChangeState(EnemyState.attack);

        if (!attacking)
        {
            atkResp = client.instance.send("E" + ID + "A" + (int)transform.position.x + "," + (int)transform.position.y);
            Debug.Log(atkResp);
            attacking = true;
            if (atkResp == "0")
            {
                ChangeState(EnemyState.walk);
                //ChangeState(EnemyState.backtrack);
                attacking = false;
                attCounter = 0;
                return;
            }

        }
        else
        {
            if (atkResp=="0")
            {
                ChangeState(EnemyState.walk);
                //ChangeState(EnemyState.backtrack);
                attacking = false;
                attCounter = 0;
            }
            else { 

                attack = atkResp.Split(';');
                if (attCounter == attack.Length)
                {
                    speed = regularSpeed;
                    attacking = false;
                    attCounter = 0;
                    ChangeState(EnemyState.walk);
                    //ChangeState(EnemyState.backtrack);

                }
                else
                {
                    
                    float x = float.Parse(attack[attCounter].Split(',')[0]);
                    float y = float.Parse(attack[attCounter].Split(',')[1]);
                    Vector2 vec;
                    vec.x = x;
                    vec.y = y;
                    Vector3 temp = Vector3.MoveTowards(transform.position, vec, speed * Time.deltaTime);
                    ChangeAnim(temp - transform.position);
                    myRigidbody.MovePosition(temp);
                    if (Vector3.Distance(transform.position, vec) == 0) 
                    {
                        client.instance.send("E" + ID + "P" + (int)transform.position.x + "," + (int)transform.position.y);
                        attCounter++; 
                    }
                }
            }
            
        }
    }
    public void Walk()
    {
        
        //animador.SetBool("despertar", false);
        speed = regularSpeed;
        if (counter == defa.Length) { counter = 0; }
        float x = float.Parse(defa[counter].Split(',')[0]);
        float y = float.Parse(defa[counter].Split(',')[1]);
        Vector2 vec;
        vec.x = x;
        vec.y = y;
        Vector3 temp = Vector3.MoveTowards(transform.position, vec, speed * Time.deltaTime);
        ChangeAnim(temp - transform.position);
        myRigidbody.MovePosition(temp);
        if (Vector3.Distance(transform.position, vec) == 0) { counter++; }
    }
    public virtual void Chase()
    {
        speed = chaseSpeed;
        Vector3 temp = Vector3.MoveTowards(transform.position, blanco.position, speed * Time.deltaTime);
        ChangeAnim(temp - transform.position);
        myRigidbody.MovePosition(temp);
        if (Vector3.Distance(transform.position, temp) == 0)
        {
            client.instance.send("E" + ID + "P" + (int)transform.position.x + "," + (int)transform.position.y);
        }
        }
    public void Alarm()
    {

        GameObject[] enemies = GameObject.FindGameObjectsWithTag("enemy");
        for (int i = 0; i < enemies.Length; i++)
        {
            if (gameObject != enemies[i])
            {
                enemies[i].GetComponent<Enemy>().currentState = EnemyState.attack;
            }
        }
        ChangeState(EnemyState.follow);



    }

    public void Alarm2()
    {
        Debug.Log("JOSEALARM");
        ChangeState(EnemyState.attack);
    }
    public virtual void FalseAlarm()
    {
        ChangeState(EnemyState.walk);
        //ChangeState(EnemyState.backtrack);
    }

    public void PlayerIsSafe()
    {
        isSafe = true;
    }
    public void PlayerNotSafe()
    {
        isSafe = false;
    }
    public void Backtrack()
    {
        if (backtrack.Count != 0)
        {

            if (Vector3.Distance(transform.position, backtrack.Peek()) != 0)
            {
                Vector3 Temp = Vector3.MoveTowards(transform.position, backtrack.Peek(), speed * Time.deltaTime);
                ChangeAnim(Temp - transform.position);
                myRigidbody.MovePosition(Temp);
            }
            else
            {
                backtrack.Pop();
            }

        }
        else { ChangeState(EnemyState.walk); }
        Debug.Log("Backtrack");
        
    }
    public void ChangeState(EnemyState newState)
    {
        if (currentState != newState)
        {
            currentState = newState;
        }
    }
    public void ChangeAnim(Vector2 direction)
    {
        if (Mathf.Abs(direction.x) > Mathf.Abs(direction.y))
        {
            if (direction.x > 0)
            {
                setAnimFloat(Vector2.right);
                facing = Vector2.right;
            }
            else if (direction.x < 0)
            {
                setAnimFloat(Vector2.left);
                facing = Vector2.left;
            }
        }
        else if (Mathf.Abs(direction.x) < Mathf.Abs(direction.y))
        {
            if (direction.y > 0)
            {
                setAnimFloat(Vector2.up);
                facing = Vector2.up;
            }
            else if (direction.y < 0)
            {
                setAnimFloat(Vector2.down);
                facing = Vector2.down;
            }

        }


    }

    public void setAnimFloat(Vector2 setVector)
    {
        animador.SetFloat("moveX", setVector.x);
        animador.SetFloat("moveY", setVector.y);
    }

}
