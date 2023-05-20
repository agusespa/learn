import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.TestInstance;

import static org.junit.jupiter.api.Assertions.*;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class RobotTest {

    @Test
    public void shouldMoveToPosition31E() {
        Room room = new Room(5, 5);
        Robot robot = new Robot("R2", 0, 0, 2, room);
        robot.executeCommand("RFLFFLRF");
        assertEquals(robot.getName() + "'s final position: 3 1 E (0 crashes)", robot.getReport());
    }

    @Test
    public void shouldThrowExceptionWhenGivenInvalidCommand() {
        Room room = new Room(5, 5);
        Robot robot = new Robot("R2", 0, 0, 2, room);
        assertThrows(IllegalArgumentException.class, () -> robot.executeCommand("RLPF"));
    }

    @Test
    public void shouldMoveToPosition13N() {
        Room room = new Room(5, 5);
        Robot robot = new Robot("R2", 1, 2, 1, room);
        robot.executeCommand("RFRFFRFRF");
        assertEquals(robot.getName() + "'s final position: 1 3 N (0 crashes)", robot.getReport());
    }

    @Test
    public void shouldReturnToPosition01W() {
        Room room = new Room(2, 2);
        Robot robot = new Robot("R2", 0, 1, 1, room);
        robot.executeCommand("FRFRFRF");
        assertEquals(robot.getName() + "'s final position: 0 1 W (0 crashes)", robot.getReport());
    }

    @Test
    public void shouldMoveToPosition30S() {
        Room room = new Room(6, 4);
        Robot robot = new Robot("R2", 4, 3, 4, room);
        robot.executeCommand("LFLFLFLFRFFFLFL");
        assertEquals(robot.getName() + "'s final position: 3 0 S (2 crashes)", robot.getReport());
    }

    @Test
    public void shouldEndWhereItStarted() {
        Room room = new Room(5, 4);
        Robot robot = new Robot("R2", 3, 2, 1, room);
        robot.executeCommand("FRFRFRFR");
        assertEquals(robot.getName() + "'s final position: 3 2 N (0 crashes)", robot.getReport());
    }

    @Test
    public void shouldEndWhereItStartedWithoutMoving() {
        Room room = new Room(0, 0);
        Robot robot = new Robot("R2", 0, 0, 1, room);
        robot.executeCommand("LFLFLFLF");
        assertEquals(robot.getName() + "'s final position: 0 0 N (4 crashes)", robot.getReport());
    }

    @Test
    public void shouldAcceptBothLowerAndUpperCaseCommands() {
        Room room = new Room(6, 4);
        Robot robot = new Robot("R2", 3, 4, 4, room);
        robot.executeCommand("lFLfLFLFrfFFFFLFL");
        assertEquals(robot.getName() + "'s final position: 2 0 S (3 crashes)", robot.getReport());
    }

    @Test
    public void shouldNotTrespassRightWall() {
        Room room = new Room(2, 2);
        Robot robot = new Robot("R2", 0, 1, 1, room);
        robot.executeCommand("rfff");
        assertEquals(robot.getName() + "'s final position: 1 1 E (2 crashes)", robot.getReport());
    }

    @Test
    public void shouldNotTrespassLeftWall() {
        Room room = new Room(2, 2);
        Robot robot = new Robot("R2", 1, 1, 1, room);
        robot.executeCommand("lfff");
        assertEquals(robot.getName() + "'s final position: 0 1 W (2 crashes)", robot.getReport());
    }

    @Test
    public void shouldNotTrespassFrontWall() {
        Room room = new Room(2, 3);
        Robot robot = new Robot("R2", 1, 2, 2, room);
        robot.executeCommand("lfff");
        assertEquals(robot.getName() + "'s final position: 1 0 N (1 crashes)", robot.getReport());
    }

    @Test
    public void shouldNotTrespassBackWall() {
        Room room = new Room(2, 3);
        Robot robot = new Robot("R2", 1, 2, 2, room);
        robot.executeCommand("lflflfff");
        assertEquals(robot.getName() + "'s final position: 0 2 S (2 crashes)", robot.getReport());
    }
}
