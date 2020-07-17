using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using UnityEngine;
using UnityEngine.Rendering;

public class Arrow : MonoBehaviour
{
    public int damage;
    public float speed;
    public Vector2 direction;
    public float lifeTime;
    private float timer;
    public Rigidbody2D rigidBody;
    public Signal hurt;
    public Signal block;
    public FloatValue playerHealth;
    public FloatValue heartContainers;
    public float amountToDecrease;
    public AudioSource arrowCast;

    // Start is called before the first frame update
    void Start()
    {
        timer = lifeTime;
        arrowCast.Play();
    }

    // Update is called once per frame
    void Update()
    {
        timer -= Time.deltaTime;
        if(lifeTime <= 0)
        {
            Destroy(this.gameObject);
        }
    }

    public void launch(Vector2 initValue)
    {
        rigidBody.velocity = initValue * speed;
    }

    public void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.CompareTag("Player") && collision.isTrigger)
        {
            if (!collision.GetComponent<MovJugador>().protect)
            {
                playerHealth.RuntimeValue -= amountToDecrease;
                client.instance.send("AS");
                hurt.Raise();
                if (playerHealth.initialValue > heartContainers.RuntimeValue)
                {
                    playerHealth.initialValue = heartContainers.RuntimeValue;
                }
            }
            //hacer daño
            block.Raise();
            
        }
        Destroy(this.gameObject);
    }
}
