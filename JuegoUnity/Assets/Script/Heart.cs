using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Heart : MonoBehaviour
{

    //public Signal heartSignal;
    //cosas de harold

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.CompareTag("Player") && !collision.isTrigger)
        {
            Destroy(this.gameObject);
            //if not max health do 
                //heartSignal.Raise();
                client.instance.send("P+1");
                // llama a harlod pa q haga lo suyo
            //else
                 //set max vida
        }
    }
}
