using UnityEngine;

public class DestroyOOB : MonoBehaviour
{
    private float topBound = 36f;
    private float bottomBound = -16f;

    void Start()
    {
    }

    void Update()
    {
        if (transform.position.z > topBound || transform.position.z < bottomBound)
        {
            Destroy(gameObject);
        }
    }
}
