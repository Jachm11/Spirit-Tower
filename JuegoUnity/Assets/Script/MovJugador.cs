using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using UnityEngine;

public enum estadoJugador
{
    camina,
    atacando,
    stagger,
    idle
}

public class MovJugador : MonoBehaviour
{
    private int ciclos = 0;
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
        animador.SetFloat("moverX", 0);
        animador.SetFloat("moverY", -1);


    }

    // Update is called once per frame
    void Update()
    {
        cambio = Vector3.zero;
        cambio.x = Input.GetAxisRaw("Horizontal");
        cambio.y = Input.GetAxisRaw("Vertical");
        if (ciclos == 250)
        {
            client.instance.send(get_Pos());
            ciclos = 0;
        }
        else
        {
            ciclos++;
        }
        if (Input.GetButtonDown("ataque") && currentState != estadoJugador.atacando && currentState != estadoJugador.stagger)
        {
            StartCoroutine(ataqueCo());
        }
        else if (currentState == estadoJugador.camina || currentState == estadoJugador.idle)
        {
            animMov();
        }


    }
    private string get_Pos()
    {
        string pos = string.Format("{0:N2}", rigidbody.position.x);
        pos = pos + ";" + string.Format("{0:N2}", rigidbody.position.y);
        return pos;
    }
    private IEnumerator ataqueCo()
    {
        animador.SetBool("atacando", true);
        currentState = estadoJugador.atacando;
        yield return null;
        animador.SetBool("atacando", false);
        yield return new WaitForSeconds(.3f);
        currentState = estadoJugador.camina;
    }
    void animMov()
    {
        if (cambio != Vector3.zero)
        {
            Movimiento();
            animador.SetFloat("moverX", cambio.x);
            animador.SetFloat("moverY", cambio.y);
            animador.SetBool("camina", true);
        }
        else
        {
            animador.SetBool("camina", false);
        }
    }

    void Movimiento()
    {
        cambio.Normalize();
        rigidbody.MovePosition(
            transform.position + cambio * Vel * Time.deltaTime
        );
    }
    public void knock(float knockTime)
    {
        StartCoroutine(knockCo(knockTime));
    }
    private IEnumerator knockCo(float KnockTime)
    {
        if (rigidbody != null)
        {
            yield return new WaitForSeconds(KnockTime);
            rigidbody.velocity = Vector2.zero;
            currentState = estadoJugador.idle;
        }
    }
}
