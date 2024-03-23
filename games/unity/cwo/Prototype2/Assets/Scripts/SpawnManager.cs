using UnityEngine;

public class SpawnManager : MonoBehaviour

{
    public GameObject[] animalPrefabs;
    private float spawnBounds = 21f;
    private float spawnDelay = 2f;
    private float spawnInterval = 1.5f;

    void Start()
    {
        InvokeRepeating("SpawnRandomAnimal", spawnDelay, spawnInterval);
    }

    void Update()
    {
    }

    void SpawnRandomAnimal() {
        int index = Random.Range(0, animalPrefabs.Length);
        GameObject animal = animalPrefabs[index];
        Vector3 position = new Vector3(Random.Range(-spawnBounds, spawnBounds), 0, 35);
        Instantiate(animal, position, animal.transform.rotation);
    }
}
