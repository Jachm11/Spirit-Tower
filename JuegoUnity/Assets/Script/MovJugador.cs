using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovJugador : MonoBehaviour
{
    public float Vel;
    private Rigidbody2D rigidbody;
    private Vector3 cambio;
    private Animator animador;
    // Start is called before the first frame update
    void Start()
    {
        animador = GetComponent<Animator>();
        rigidbody = GetComponent<Rigidbody2D>();
        

    }

    // Update is called once per frame
    void Update()
    {
        cambio = Vector3.zero;
        cambio.x = Input.GetAxisRaw("Horizontal");
        cambio.y = Input.GetAxisRaw("Vertical");
        animMov();
        
    }
    void animMov(){
        if(cambio != Vector3.zero){
            Movimiento();
            animador.SetFloat("moverX",cambio.x);
            animador.SetFloat("moverY",cambio.y);
            animador.SetBool("camina",true);
        }else{
            animador.SetBool("camina",false);
        }
    }

    void Movimiento(){
        rigidbody.MovePosition(
            transform.position + cambio * Vel * Time.deltaTime
        );
    }
}
