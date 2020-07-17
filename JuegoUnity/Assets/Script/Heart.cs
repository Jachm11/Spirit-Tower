using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Heart : Powerup
{
    public FloatValue playerHealth;
    public FloatValue heartContainers;
    public float amountToIncrease;
    public AudioSource heartSound;

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

            playerHealth.RuntimeValue += amountToIncrease;
            client.instance.send("P+1");
            if (playerHealth.initialValue > heartContainers.RuntimeValue) 
            {
                playerHealth.initialValue = heartContainers.RuntimeValue;
            }   
            powerupSignal.Raise();
            Destroy(this.gameObject);
        }
    }
}
