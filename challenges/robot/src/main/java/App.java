import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class App {

    public static void main(String[] args) throws IOException {

        System.out.println("Welcome to your robot's controller!");

        System.out.print("Before issuing commands, you should give it a name (please be kind, think of our future robot overlords): ");

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        String robotName = reader.readLine();

        System.out.println("*** Let's set up its room");
        System.out.print("How wide is it? ");
        int widthSelection = 0;
        while (widthSelection == 0) {
            String widthSelectionLine = reader.readLine();
            try {
                widthSelection = Integer.parseInt(widthSelectionLine);
                if (widthSelection < 1) throw new IllegalArgumentException();
            } catch (IllegalArgumentException e) {
                System.out.println("Please enter a valid number");
            }
        }

        System.out.print("How long is it? ");
        int lengthSelection = 0;
        while (lengthSelection == 0) {
            String widthSelectionLine = reader.readLine();
            try {
                lengthSelection = Integer.parseInt(widthSelectionLine);
                if (lengthSelection < 1) throw new IllegalArgumentException();
            } catch (IllegalArgumentException e) {
                System.out.println("Please enter a valid number");
            }
        }

        System.out.println("*** Let's place " + robotName);
        System.out.print("Which place in the x axis (0 indexed)? ");
        int xSelection = -1;
        while (xSelection == -1) {
            String widthSelectionLine = reader.readLine();
            try {
                xSelection = Integer.parseInt(widthSelectionLine);
                if (xSelection < 0 || xSelection + 1 > widthSelection) throw new IllegalArgumentException();
            } catch (IllegalArgumentException e) {
                System.out.println("Please enter a valid number");
            }
        }

        System.out.print("Which place in the y axis (0 indexed)? ");
        int ySelection = -1;
        while (ySelection == -1) {
            String widthSelectionLine = reader.readLine();
            try {
                ySelection = Integer.parseInt(widthSelectionLine);
                if (ySelection < 0 || ySelection + 1 > lengthSelection) throw new IllegalArgumentException();
            } catch (IllegalArgumentException e) {
                System.out.println("Please enter a valid number");
            }
        }

        System.out.print("Which direction is it facing (N, E, S or W)? ");
        int directionSelection = 0;
        while (directionSelection == 0) {
            String directionSelectionLine = reader.readLine();
            try {
                directionSelection = switch (directionSelectionLine.toUpperCase()) {
                    case "N" -> 1;
                    case "E" -> 2;
                    case "S" -> 3;
                    case "W" -> 4;
                    default -> throw new IllegalArgumentException();
                };
            } catch (IllegalArgumentException e) {
                System.out.println("Please enter a valid orientation");
            }
        }

        Room room = new Room(widthSelection, lengthSelection);
        Robot robot = new Robot(robotName, xSelection, ySelection, directionSelection, room);

        System.out.println("*** Let's get " + robotName + " moving!");
        String loopCondition = "y";
        while (loopCondition.equals("y")) {
            System.out.print("Enter the commands (you can enter as many as you want): ");
            String commandSequence = reader.readLine();
            System.out.println("Executing movement...");
            robot.executeCommand(commandSequence);
            System.out.println(robot.getReport());

            System.out.print("Do you want to continue? y/n " );
            loopCondition = reader.readLine().toLowerCase();
        }

        System.out.println("*** Turning " + robot.getName() + " off...");
    }
}
