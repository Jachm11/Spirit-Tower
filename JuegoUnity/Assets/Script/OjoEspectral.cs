using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OjoEspectral : MonoBehaviour
{
    public Transform target;
    public int range;
    public Signal alarm;
    public Signal falseAlarm;
    public AudioSource alarmSound;
    public bool activeCall = false;

    // Start is called before the first frame update
    void Start()
    {
        target = GameObject.FindWithTag("Player").transform;
    }

    // Update is called once per frame
    void Update()
    {
        if (Vector3.Distance(target.position, transform.position) <= range)
        {

            alarm.Raise();
            if (!activeCall)
            {
                
                alarmSound.Play();
                activeCall = true;
            }
           
        }
        else
        {
            falseAlarm.Raise();
            alarmSound.Stop();
            activeCall = false;
        }
        
    }
}
