using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public enum EnemyState
{
    idle,
    walk,
    attack,
    alarm,
    stagger,
    backtrack,
    follow
}
public class Enemy : MonoBehaviour
{
    public EnemyState currentState;
    public FloatValue maxHealth;
    public float life;
    public int pts;
    public string ID;
    public float speed;
    public int baseAttack;
    public Inventory playerInventory;
    public Signal coinSignal;


    private void Awake()
    {
        life = maxHealth.initialValue;
    }

    private void TakeDamage(float damage)
    {
        life -= damage;
        if (life <= 0)
        {
            if (this.CompareTag("Raton"))
            {
                client.instance.send("MOB");
                client.instance.send("L" +pts);
                playerInventory.puntos += 10;
                coinSignal.Raise();
            }
            else if (this.CompareTag("espec"))
            {
                client.instance.send("E"+ID+"M");
                client.instance.send("L"+pts);
                playerInventory.puntos += 30;
                coinSignal.Raise();
            }
       
            this.gameObject.SetActive(false);
        }
    }
    public void Knock(Rigidbody2D myRigidBody, float knockTime, float damage)
    {
        StartCoroutine(KnockCo(myRigidBody, knockTime));
        TakeDamage(damage);
    }
    private IEnumerator KnockCo(Rigidbody2D myRigidBody, float knockTime)
    {
        if (myRigidBody != null)
        {
            yield return new WaitForSeconds(knockTime);
            myRigidBody.velocity = Vector2.zero;
            currentState = EnemyState.idle;
            myRigidBody.velocity = Vector2.zero;
        }
    }
    
}
