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

    // Start is called before the first frame update
    void Start()
    {
        timer = lifeTime;
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
        if (collision.CompareTag("Player") && !collision.isTrigger)
        {
            //hacer daño
            client.instance.send("atack simp");
        }
        Destroy(this.gameObject);
    }
}
