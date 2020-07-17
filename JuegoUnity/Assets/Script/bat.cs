using System.Collections;
using System.Collections.Generic;
using Unity.Mathematics;
using UnityEngine;
using UnityEngine.UIElements;

public class bat : boss 
{
    private Rigidbody2D myrigidBody;
    public Transform target;
    public float chaseRadius;
    public float attackRadius;
    public Transform Homeposicion;
    public Animator anim;

    public void Awake()
    {
        health = maxHealth.initialValue;
    }
    // Start is called before the first frame update
    void Start()
    {
        currentState = BossState.idle;
        myrigidBody = GetComponent<Rigidbody2D>();
        target = GameObject.FindWithTag("Player").transform;
        anim = GetComponent<Animator>();
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        checkDistance();
    }
    void checkDistance()
    {
        if(Vector3.Distance(target.position,transform.position)<= chaseRadius && Vector3.Distance(target.position,transform.position)>attackRadius)
        {
            if (currentState == BossState.idle || currentState == BossState.walk && currentState != BossState.stagger)
            {

                Vector3 temp = Vector3.MoveTowards(transform.position, target.position, speed * Time.deltaTime);
                chanceAnim(temp - transform.position);
                myrigidBody.MovePosition(temp);
                changeState(BossState.walk);
            }
        }
    }
    private void setAnimFloat(Vector2 setVector)
    {
        anim.SetFloat("moveX", setVector.x);
        anim.SetFloat("moveY", setVector.y);
    }
    private void chanceAnim(Vector2 direcc)
    {
        if (Mathf.Abs(direcc.x) > Mathf.Abs(direcc.y))
        {
            if(direcc.x > 0)
            {
                setAnimFloat(Vector2.right);
            }else if (direcc.x < 0)
            {
                setAnimFloat(Vector2.left);
            }
        }else if (Mathf.Abs(direcc.x) < Mathf.Abs(direcc.y))
        {
            if (direcc.y > 0)
            {
                setAnimFloat(Vector2.up);
            }
            else if (direcc.y < 0)
            {
                setAnimFloat(Vector2.down);
            }

        }
    }
    private void changeState(BossState newState)
    {
        if(currentState != newState)
        {
            currentState = newState;
        }
    }
}
