using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public enum estadoJugador{
    camina,
    atacando
}

public class MovJugador : MonoBehaviour
{
    public estadoJugador currentState;
    public float Vel;
    private Rigidbody2D rigidbody;
    private Vector3 cambio;
    private Animator animador;
    // Start is called before the first frame update
    void Start()
    {
        currentState = estadoJugador.camina;
        animador = GetComponent<Animator>();
        rigidbody = GetComponent<Rigidbody2D>();
        

    }

    // Update is called once per frame
    void Update()
    {
        cambio = Vector3.zero;
        cambio.x = Input.GetAxisRaw("Horizontal");
        cambio.y = Input.GetAxisRaw("Vertical");
        if(Input.GetButtonDown("ataque")&& currentState != estadoJugador.atacando){
            StartCoroutine(ataqueCo());
        }
        else if(currentState == estadoJugador.camina){
            animMov();
        }
        
    }
    private IEnumerator ataqueCo(){
            animador.SetBool("atacando",true);
            currentState = estadoJugador.atacando;
            yield return null;
            animador.SetBool("atacando",false);
            yield return new WaitForSeconds(.3f);
            currentState = estadoJugador.camina;
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
