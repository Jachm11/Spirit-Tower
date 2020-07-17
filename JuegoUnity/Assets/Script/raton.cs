using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class raton : Enemy
{
    public Rigidbody2D rigidBody;
    public float amountToDecrease;
    public int velCambio;
    private int ciclos;
    private Animator anim;


    // Start is called before the first frame update
    void Start()
    {
        anim = GetComponent<Animator>();
        Vector2 randomVector = Random.insideUnitCircle;
        randomVector = randomVector.normalized;
        run(randomVector);
        ciclos = 0;
    }

    // Update is called once per frame
    void Update()
    {
        if (ciclos == velCambio)
        {
            Vector2 randomVector = Random.insideUnitCircle;
            randomVector = randomVector.normalized;
            run(randomVector);
            ciclos = 0;
        }
        else
        {
            ciclos++;
        }
    }


    private void run(Vector2 initValue)
    {

        rigidBody.velocity = initValue * speed;
        anim.SetFloat("moveX", initValue.x);
        anim.SetFloat("moveY", initValue.y);
    }


}
