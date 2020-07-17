using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Lock : MonoBehaviour
{

    public GameObject bossLock;
    // Start is called before the first frame update
    private void Awake()
    {
        GameObject.FindGameObjectWithTag("Music").GetComponent<AudioManager>().StopMusic();
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        GameObject.FindGameObjectWithTag("Music").GetComponent<AudioManager>().PlayMusic();
        bossLock.SetActive(true);

    }
}
