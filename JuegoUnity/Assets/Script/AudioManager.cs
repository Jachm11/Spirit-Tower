using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AudioManager : MonoBehaviour
{

    public AudioSource self;
    public AudioSource bossTheme;
    public AudioSource died;
    public AudioSource breakPot;
    public AudioSource block;
    public AudioSource hit;
    public AudioSource wind;
    public AudioSource victory;

    private static AudioManager playerInstance;
    private void Awake()
    {

        //self = GetComponent<AudioSource>();
        DontDestroyOnLoad(this);

        if (playerInstance == null)
        {
            playerInstance = this;
        }
        else
        {
            DestroyObject(gameObject);
        }
    }

    public void PlayMusic()
    {
        wind.Stop();
        if (bossTheme.isPlaying) return;
        bossTheme.Play();
    }

    public void StopMusic()
    {
        self.Stop();
        wind.Play();
    }

    public void StopBoss()
    {
        bossTheme.Stop();
    }

    public void playDeath()
    {
        died.Play();
    }

    public void playBreakPot()
    {
        breakPot.Play();
    }

    public void playBlocked()
    {
        block.Play();
    }
    public void playHit()
    {
        hit.Play();
    }

    public void playVictory()
    {
        victory.Play();
    }
 
}

