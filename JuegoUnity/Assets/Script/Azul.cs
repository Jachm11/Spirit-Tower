using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics.Tracing;
using System.Runtime.CompilerServices;
using UnityEngine;
using UnityEngine.Rendering;

public class Azul : Gris
{
    public override void Attack()
    {
        GameObject[] ojos = GameObject.FindGameObjectsWithTag("ojo");
        for (int i = 0; i < ojos.Length; i++)
        {
            if (ojos[i].GetComponent<OjoEspectral>().activeCall)
                myRigidbody.transform.position = new Vector2(ojos[i].transform.position.x, ojos[i].transform.position.y);
        }
        Debug.Log("Azul atacando");
        ChangeState(EnemyState.follow);
        if (!attacking)
        {
            atkResp = client.instance.send("E" + ID + "A" + (int)transform.position.x + "," + (int)transform.position.y);
            Debug.Log(atkResp);
            attacking = true;
            if (atkResp == "0")
            {
                Debug.Log("HIICC!!!");
                ChangeState(EnemyState.walk);
                attacking = false;
                attCounter = 0;
                return;
            }

        }
        else
        {
            if (atkResp =="0")
            {
                ChangeState(EnemyState.walk);
                attacking = false;
                attCounter = 0;
            }
            else
            {

                attack = atkResp.Split(';');
                if (attCounter == attack.Length)
                {
                    speed = regularSpeed;
                    attacking = false;
                    attCounter = 0;
                    ChangeState(EnemyState.walk);

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
                    if (Vector3.Distance(transform.position, vec) == 0) { attCounter++; }
                }
            }

        }
    }
    public override void FalseAlarm()
    {
        //float x = float.Parse(attack[attCounter].Split(',')[0]);
        //float y = float.Parse(attack[attCounter].Split(',')[1]);
        //Vector2 vec;
        //vec.x = x;
        //vec.y = y;
        //myRigidbody.transform.position = vec;
        ChangeState(EnemyState.walk);
        //ChangeState(EnemyState.backtrack);
    }
}
   