using System.Collections;
using System.Collections.Generic;
using UnityEngine;



public class Espectro : MonoBehaviour
{
   
    public FloatValue maxHealth;
    public string ID;
    public float speed;
    public float life;
    public int baseAttack;
    public float chaseSpeed;
    public float regularSpeed;
    public float range;
    

    public Vector2 target;

    private void Awake()
    {
        life = maxHealth.initialValue;
    }

    // Start is called before the first frame update
    
    
    void Start()
    {
        

    }

    // Update is called once per frame
    void Update()
    {
        
    }
   
    
    protected void Go()
    {
        target = new Vector2(transform.position.x, transform.position.y);
        client.instance.send("E" + ID  + "stats");
    }
    protected void Move()
    {
        if (target.x == transform.position.x && target.y == transform.position.y)
        {
            string resp = client.instance.send("E" + ID + "move");
            target = new Vector2(float.Parse(resp.Split(',')[1]), 24.0f - float.Parse(resp.Split(',')[0]));

        }
    }
    protected void Attack()
    {

        client.instance.send("E" + ID + "attack");


    }
    protected void Stop()
    {
        client.instance.send("E" + ID +"stop");

    }
}
