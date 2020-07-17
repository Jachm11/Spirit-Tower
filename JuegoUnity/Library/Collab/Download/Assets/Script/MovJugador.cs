using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.SceneManagement;

public enum estadoJugador
{
    camina,
    atacando,
    stagger,
    interactua,
    idle,
    protegiendo
}

public class MovJugador : MonoBehaviour
{
    private int ciclos = 0;
    public estadoJugador currentState;
    public float Vel;
    private Rigidbody2D rigidbody;
    private Vector3 cambio;
    private Animator animador;
    public FloatValue currentHealth;
    public Signal playerHealthSignal;
    public Signal playerPtsSignal;
    public bool protect = false;
    public Item moneda;
    public SpriteRenderer spriteItemRecivido;
    public Inventory playerInventory;
    public AudioSource swing;
    public AudioSource hit;
    public AudioSource block;
    public AudioSource died;

    private void Awake()
    {
        //DontDestroyOnLoad(transform.gameObject);
    }

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
        if (currentState == estadoJugador.interactua)
        {
            return;
        }
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
        if (Input.GetButtonDown("ataque") && currentState != estadoJugador.atacando && currentState != estadoJugador.stagger && currentState != estadoJugador.protegiendo)
        {
            StartCoroutine(ataqueCo());
        }
        else if (Input.GetButtonDown("proteger") && currentState != estadoJugador.atacando && currentState != estadoJugador.stagger && currentState != estadoJugador.protegiendo)
        {
            StartCoroutine(ProtegerCo());
        }
        else if (currentState == estadoJugador.camina || currentState == estadoJugador.idle)
        {
            animMov();
        }
        playerHealthSignal.Raise();
        playerPtsSignal.Raise();
        comprobarVida();

    }
    private string get_Pos()
    {
        string pos = "pos;"+ string.Format("{0:N2}", rigidbody.position.x);
        pos = pos + ";" + string.Format("{0:N2}", rigidbody.position.y);
        return pos;
    }
    public void comprobarVida()
    {
        if(currentHealth.RuntimeValue == 0)
        {
            respawn();
        }
    }
    private void respawn()
    {
        client.instance.send("muerte");
        Scene scene = SceneManager.GetActiveScene();
        SceneManager.LoadScene(scene.name);
        died.Play();
        currentHealth.RuntimeValue = 5;
    }
    private IEnumerator ataqueCo()
    {
        animador.SetBool("atacando", true);
        currentState = estadoJugador.atacando;
        yield return null;
        animador.SetBool("atacando", false);
        swing.Play();
        yield return new WaitForSeconds(.3f);
        if (currentState != estadoJugador.interactua)
        {
            currentState = estadoJugador.camina;
        }


    }

    public void RaiseItem()
    {
        if (playerInventory.itemActual != null)
        {
            if (currentState != estadoJugador.interactua)
            {
                animador.SetBool("recivir item", true);
                currentState = estadoJugador.interactua;
                spriteItemRecivido.sprite = moneda.itemSprite;
            }
            else
            {
                animador.SetBool("recivir item", false);
                currentState = estadoJugador.idle;
                spriteItemRecivido.sprite = null;
                //playerInventory.itemActual = null;
            }
        }
    }

    private IEnumerator ProtegerCo()
    {
        protect = true;
        animador.SetBool("protegiendo", true);
        block.Play();
        currentState = estadoJugador.protegiendo;
        yield return null;
        animador.SetBool("protegiendo", false);
        yield return new WaitForSeconds(.3f);
        protect = false;
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
    public void knock(float knockTime, float damage)
    {
        if (!protect)
        {
            currentHealth.RuntimeValue -= damage;
            hit.Play();
            client.instance.send("AS");
            playerHealthSignal.Raise();
            if (currentHealth.RuntimeValue > 0) //al hacer modificación al floatValue cambiar el initialValue por runtime
            {
                StartCoroutine(knockCo(knockTime));
            }
        }
        else
        {
            StartCoroutine(knockCo(knockTime));

        }

    }
    private IEnumerator knockCo(float KnockTime)
    {
        if (rigidbody != null)
        {
            yield return new WaitForSeconds(KnockTime);
            rigidbody.velocity = Vector2.zero;
            currentState = estadoJugador.idle;
            rigidbody.velocity = Vector2.zero;
        }
    }
}