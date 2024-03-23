using UnityEngine;

public class FollowPlayerX : MonoBehaviour
{
    public Transform plane;
    private Vector3 offset = new Vector3(10,2,0);

    void Start()
    {

    }

    void LateUpdate()
    {
        transform.position = plane.transform.position + offset;
        transform.LookAt(plane);
    }
}
