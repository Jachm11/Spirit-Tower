using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
public class Loot 
{
    public Heart loot;
    public int lootChance;
}


[CreateAssetMenu]
public class LootTable : ScriptableObject
{
    public Loot[] loots;

    public Heart lootheart()
    {

        int probAcumulada = 0;
        int currentProb = Random.Range(0, 100);
        for (int i = 0; i< loots.Length; i++)
        {
            probAcumulada += loots[i].lootChance;
            if (currentProb <= probAcumulada)
            {
                return loots[i].loot;
            }
        }
        return null;
    }
}
