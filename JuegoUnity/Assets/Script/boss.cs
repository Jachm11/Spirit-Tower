using System.Collections;
using System.Collections.Generic;
using System.Transactions;
using UnityEngine;
using UnityEngine.SceneManagement;
using System.Threading;

public enum BossState
{
    idle,
    walk,
    attack,
    stagger
}
public class boss : MonoBehaviour
{
    public BossState currentState;
    public FloatValue maxHealth;
    public float health;
    public int baseAttack;
    public float speed;
    public Signal bossHealthSignal;

    private void TakeDamage(float damage)
    {
        health -= damage;
        maxHealth.RuntimeValue -= damage;
        bossHealthSignal.Raise();
        if (health <= 0)
        {
            client.instance.send("L9");
            this.gameObject.SetActive(false);
            Thread.Sleep(1200);
            SceneManager.LoadScene("Win menu");
        }
    }
    public void knock(Rigidbody2D rigidbody, float knockTime, float damage)
    {
        StartCoroutine(knockCo(rigidbody, knockTime));
        TakeDamage(damage);

    }
   
    private IEnumerator knockCo(Rigidbody2D rigidBody, float knockTime)
    {
        if (rigidBody != null)
        {
            yield return new WaitForSeconds(knockTime);
            rigidBody.velocity = Vector2.zero;
            currentState = BossState.idle;
            rigidBody.velocity = Vector2.zero;
        }
    }
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    
    
}
