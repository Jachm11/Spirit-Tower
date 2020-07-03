using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class pot : MonoBehaviour
{

    private Animator anim;

    // Start is called before the first frame update
    void Start()
    {
        anim = GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            Smash();
        }
    }

    public void Smash()
    {
        anim.SetBool("smash", true);
        StartCoroutine(breakCo());
        client.instance.send("OPD"); // Object Pot Destroyed
    }

    IEnumerator breakCo()
    {
        yield return new WaitForSeconds(.3f);
        this.gameObject.SetActive(false);
    }
}
