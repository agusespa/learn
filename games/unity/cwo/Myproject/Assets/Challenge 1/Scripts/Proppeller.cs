using UnityEngine;

public class Proppeller : MonoBehaviour
{
    void Start()
    { }

    void Update()
    {
        transform.Rotate(Vector3.forward * Time.deltaTime * 200);
    }
}
