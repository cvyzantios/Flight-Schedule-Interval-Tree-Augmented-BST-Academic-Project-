using System;


// ============================================================
// TIME
// ============================================================

// Stores a time using hours and minutes.
// Αποθηκεύει μία ώρα χρησιμοποιώντας ώρες και λεπτά.
public struct Time
{
    public int Hour { get; set; }
    public int Minute { get; set; }


    // Constructor.
    // Κατασκευαστής.
    public Time(int hour = 0, int minute = 0)
    {
        Hour = hour;
        Minute = minute;
    }


    // Converts the time to total minutes.
    // Μετατρέπει την ώρα σε συνολικά λεπτά.
    //
    // This makes time comparisons much easier.
    // Αυτό κάνει πολύ ευκολότερες τις συγκρίσεις μεταξύ ωρών.
    public int ToMinutes()
    {
        return Hour * 60 + Minute;
    }


    // Checks whether this time is before another time.
    // Ελέγχει αν αυτή η ώρα είναι πριν από μία άλλη ώρα.
    public bool IsBefore(Time other)
    {
        return ToMinutes() < other.ToMinutes();
    }


    // Checks whether this time is after another time.
    // Ελέγχει αν αυτή η ώρα είναι μετά από μία άλλη ώρα.
    public bool IsAfter(Time other)
    {
        return ToMinutes() > other.ToMinutes();
    }


    // Checks whether this time is before or equal to another time.
    // Ελέγχει αν αυτή η ώρα είναι πριν ή ίση με μία άλλη.
    public bool IsBeforeOrEqual(Time other)
    {
        return ToMinutes() <= other.ToMinutes();
    }


    // Checks whether this time is after or equal to another time.
    // Ελέγχει αν αυτή η ώρα είναι μετά ή ίση με μία άλλη.
    public bool IsAfterOrEqual(Time other)
    {
        return ToMinutes() >= other.ToMinutes();
    }


    // Checks whether two times are equal.
    // Ελέγχει αν δύο ώρες είναι ίσες.
    public bool IsEqual(Time other)
    {
        return ToMinutes() == other.ToMinutes();
    }


    // Returns the time as HH:MM.
    // Επιστρέφει την ώρα στη μορφή HH:MM.
    public override string ToString()
    {
        return $"{Hour:D2}:{Minute:D2}";
    }
}



// ============================================================
// FLIGHT
// ============================================================

// Stores all information about one flight.
// Αποθηκεύει όλες τις πληροφορίες για μία πτήση.
public class Flight
{
    private string flightCode;

    private Time departure;

    private Time arrival;


    // Constructor.
    // Κατασκευαστής.
    public Flight(
        string code = "",
        Time dep = new Time(),
        Time arr = new Time())
    {
        flightCode = code;
        departure = dep;
        arrival = arr;
    }


    // Returns the flight code.
    // Επιστρέφει τον κωδικό της πτήσης.
    public string GetFlightCode()
    {
        return flightCode;
    }


    // Returns the departure time.
    // Επιστρέφει την ώρα αναχώρησης.
    public Time GetDeparture()
    {
        return departure;
    }


    // Returns the arrival time.
    // Επιστρέφει την ώρα άφιξης.
    public Time GetArrival()
    {
        return arrival;
    }


    // Displays the flight information.
    // Εμφανίζει τις πληροφορίες της πτήσης.
    public void Display()
    {
        Console.WriteLine(
            $"{flightCode} | Departure: {departure} | Arrival: {arrival}");
    }
}



// ============================================================
// NODE
// ============================================================

// One node of the Binary Search Tree.
// Ένας κόμβος του Δυαδικού Δέντρου Αναζήτησης.
public class Node
{
    private Flight data;

    private Node left;

    private Node right;

    private Node parent;


    // Maximum arrival time inside this node's subtree.
    // Η μέγιστη ώρα άφιξης μέσα στο υποδέντρο αυτού του κόμβου.
    private Time maxArrival;


    // Constructor.
    // Κατασκευαστής.
    public Node(Flight flight)
    {
        data = flight;

        left = null;

        right = null;

        parent = null;


        // Initially, the maximum arrival is the arrival
        // of the flight stored in this node.
        //
        // Αρχικά, η μέγιστη ώρα άφιξης είναι η ώρα άφιξης
        // της πτήσης που βρίσκεται στον συγκεκριμένο κόμβο.
        maxArrival = flight.GetArrival();
    }


    // Returns the flight stored in this node.
    // Επιστρέφει την πτήση που είναι αποθηκευμένη στον κόμβο.
    public Flight GetData()
    {
        return data;
    }


    // Returns the left child.
    // Επιστρέφει το αριστερό παιδί.
    public Node GetLeft()
    {
        return left;
    }


    // Returns the right child.
    // Επιστρέφει το δεξί παιδί.
    public Node GetRight()
    {
        return right;
    }


    // Returns the parent.
    // Επιστρέφει τον γονέα.
    public Node GetParent()
    {
        return parent;
    }


    // Returns the maximum arrival time of the subtree.
    // Επιστρέφει τη μέγιστη ώρα άφιξης του υποδέντρου.
    public Time GetMaxArrival()
    {
        return maxArrival;
    }


    // Sets the left child.
    // Ορίζει το αριστερό παιδί.
    public void SetLeft(Node node)
    {
        left = node;
    }


    // Sets the right child.
    // Ορίζει το δεξί παιδί.
    public void SetRight(Node node)
    {
        right = node;
    }


    // Sets the parent.
    // Ορίζει τον γονέα.
    public void SetParent(Node node)
    {
        parent = node;
    }


    // Sets the maximum arrival time.
    // Ορίζει τη μέγιστη ώρα άφιξης.
    public void SetMaxArrival(Time time)
    {
        maxArrival = time;
    }


    // Replaces the flight stored in this node.
    // Αντικαθιστά την πτήση που είναι αποθηκευμένη στον κόμβο.
    public void SetData(Flight flight)
    {
        data = flight;
    }
}



// ============================================================
// TREE
// ============================================================

// Binary Search Tree for airline flights.
// Δυαδικό Δέντρο Αναζήτησης για πτήσεις.
//
// The tree is ordered by departure time.
// Το δέντρο ταξινομείται με βάση την ώρα αναχώρησης.
public class Tree
{
    private Node root;


    // Constructor.
    // Κατασκευαστής.
    public Tree()
    {
        root = null;
    }


    // Returns the root of the tree.
    // Επιστρέφει τη ρίζα του δέντρου.
    public Node GetRoot()
    {
        return root;
    }


    // Returns the maximum of two times.
    // Επιστρέφει τη μεγαλύτερη από δύο ώρες.
    private Time Maximum(Time a, Time b)
    {
        if (a.IsAfter(b))
            return a;

        return b;
    }


    // Updates the MaxArrival value of one node.
    // Ενημερώνει την τιμή MaxArrival ενός κόμβου.
    private void UpdateMaxArrival(Node node)
    {
        if (node == null)
            return;


        // Start with the arrival time of the flight
        // stored in the current node.
        //
        // Ξεκινάμε με την ώρα άφιξης της πτήσης
        // που βρίσκεται στον συγκεκριμένο κόμβο.
        Time maximumArrival =
            node.GetData().GetArrival();


        // Check the left subtree.
        // Ελέγχουμε το αριστερό υποδέντρο.
        if (node.GetLeft() != null)
        {
            maximumArrival =
                Maximum(
                    maximumArrival,
                    node.GetLeft().GetMaxArrival()
                );
        }


        // Check the right subtree.
        // Ελέγχουμε το δεξί υποδέντρο.
        if (node.GetRight() != null)
        {
            maximumArrival =
                Maximum(
                    maximumArrival,
                    node.GetRight().GetMaxArrival()
                );
        }


        node.SetMaxArrival(maximumArrival);
    }


    // Updates MaxArrival from a node up to the root.
    // Ενημερώνει το MaxArrival από έναν κόμβο μέχρι τη ρίζα.
    private void UpdateUpwards(Node node)
    {
        while (node != null)
        {
            UpdateMaxArrival(node);

            node = node.GetParent();
        }
    }


    // Finds a flight by its code.
    // Βρίσκει μία πτήση με βάση τον κωδικό της.
    private Node FindByCode(Node node, string code)
    {
        if (node == null)
            return null;


        if (node.GetData().GetFlightCode() == code)
            return node;


        Node result =
            FindByCode(node.GetLeft(), code);


        if (result != null)
            return result;


        return FindByCode(node.GetRight(), code);
    }


    // Finds the node with the smallest departure time
    // in a subtree.
    //
    // Βρίσκει τον κόμβο με τη μικρότερη ώρα αναχώρησης
    // μέσα σε ένα υποδέντρο.
    private Node Minimum(Node node)
    {
        while (node != null &&
               node.GetLeft() != null)
        {
            node = node.GetLeft();
        }

        return node;
    }


    // Removes a node that has at most one child.
    // Διαγράφει έναν κόμβο που έχει το πολύ ένα παιδί.
    private void RemoveNodeWithAtMostOneChild(Node node)
    {
        Node child = null;


        if (node.GetLeft() != null)
            child = node.GetLeft();
        else
            child = node.GetRight();


        Node parent = node.GetParent();


        // If the node is the root.
        // Αν ο κόμβος είναι η ρίζα.
        if (parent == null)
        {
            root = child;

            if (child != null)
                child.SetParent(null);
        }
        else
        {
            // Connect the child to the parent.
            // Συνδέουμε το παιδί με τον γονέα.

            if (parent.GetLeft() == node)
                parent.SetLeft(child);
            else
                parent.SetRight(child);


            if (child != null)
                child.SetParent(parent);


            // The subtree has changed.
            // Το υποδέντρο έχει αλλάξει.
            UpdateUpwards(parent);
        }


        // In C#, we do not explicitly use delete.
        // Στην C# δεν χρησιμοποιούμε ρητά delete.
        //
        // The Garbage Collector will eventually
        // remove the unused object.
        //
        // Ο Garbage Collector θα απομακρύνει τελικά
        // το αντικείμενο που δεν χρησιμοποιείται πλέον.
    }


    // Recursive function for displaying the tree.
    // Αναδρομική συνάρτηση για την εμφάνιση του δέντρου.
    private void DisplayInOrder(Node node)
    {
        if (node == null)
            return;


        DisplayInOrder(node.GetLeft());


        Console.WriteLine("----------------------------------------");

        node.GetData().Display();

        Console.WriteLine(
            $"Max Arrival in subtree: {node.GetMaxArrival()}");


        DisplayInOrder(node.GetRight());
    }


    // Searches for one flight in a time interval.
    // Αναζητά μία πτήση που βρίσκεται σε εξέλιξη
    // μέσα σε ένα χρονικό διάστημα.
    private Node FindOneInInterval(
        Node node,
        Time start,
        Time end)
    {
        if (node == null)
            return null;


        // The current flight is active during the interval
        // if the two time intervals overlap.
        //
        // Η τρέχουσα πτήση βρίσκεται σε εξέλιξη αν
        // τα δύο χρονικά διαστήματα επικαλύπτονται.
        //
        // [departure, arrival]
        // [start, end]
        //
        // Overlap condition:
        // departure <= end AND arrival >= start
        //
        // Συνθήκη επικάλυψης:
        // αναχώρηση <= τέλος ΚΑΙ άφιξη >= αρχή.
        if (node.GetData().GetDeparture().IsBeforeOrEqual(end) &&
            node.GetData().GetArrival().IsAfterOrEqual(start))
        {
            return node;
        }


        // Search the left subtree only if it may contain
        // a relevant flight.
        //
        // Εξετάζουμε το αριστερό υποδέντρο μόνο αν μπορεί
        // να περιέχει σχετική πτήση.
        if (node.GetLeft() != null &&
            node.GetLeft().GetMaxArrival().IsAfterOrEqual(start))
        {
            Node result =
                FindOneInInterval(
                    node.GetLeft(),
                    start,
                    end
                );


            if (result != null)
                return result;
        }


        // Search the right subtree if departures can still
        // fall before or inside the query interval.
        //
        // Εξετάζουμε το δεξί υποδέντρο αν οι αναχωρήσεις
        // μπορούν ακόμη να βρίσκονται πριν ή μέσα στο διάστημα.
        if (node.GetRight() != null &&
            node.GetData().GetDeparture().IsBeforeOrEqual(end))
        {
            return FindOneInInterval(
                node.GetRight(),
                start,
                end
            );
        }


        return null;
    }


    // Finds all flights active during an interval.
    // Βρίσκει όλες τις πτήσεις που βρίσκονται σε εξέλιξη
    // μέσα σε ένα χρονικό διάστημα.
    private void FindAllInInterval(
        Node node,
        Time start,
        Time end)
    {
        if (node == null)
            return;


        // Search left subtree only if it may contain
        // a relevant flight.
        //
        // Εξετάζουμε το αριστερό υποδέντρο μόνο αν μπορεί
        // να περιέχει σχετική πτήση.
        if (node.GetLeft() != null &&
            node.GetLeft().GetMaxArrival().IsAfterOrEqual(start))
        {
            FindAllInInterval(
                node.GetLeft(),
                start,
                end
            );
        }


        // Check current flight.
        // Ελέγχουμε την τρέχουσα πτήση.
        if (node.GetData().GetDeparture().IsBeforeOrEqual(end) &&
            node.GetData().GetArrival().IsAfterOrEqual(start))
        {
            node.GetData().Display();
        }


        // Search right subtree if its departures can still
        // be relevant.
        //
        // Εξετάζουμε το δεξί υποδέντρο αν οι αναχωρήσεις του
        // μπορούν ακόμη να σχετίζονται με το διάστημα.
        if (node.GetRight() != null &&
            node.GetData().GetDeparture().IsBeforeOrEqual(end))
        {
            FindAllInInterval(
                node.GetRight(),
                start,
                end
            );
        }
    }


    // Returns the latest arrival among flights
    // that departed before a specified time.
    //
    // Επιστρέφει τη μεγαλύτερη ώρα άφιξης μεταξύ των πτήσεων
    // που αναχώρησαν πριν από μία συγκεκριμένη ώρα.
    private void LatestArrivalBefore(
        Node node,
        Time h,
        ref Time bestArrival,
        ref bool found)
    {
        if (node == null)
            return;


        if (node.GetData().GetDeparture().IsBefore(h))
        {
            // The current flight qualifies.
            // Η τρέχουσα πτήση πληροί την προϋπόθεση.
            if (!found ||
                node.GetData().GetArrival().IsAfter(bestArrival))
            {
                bestArrival =
                    node.GetData().GetArrival();

                found = true;
            }


            // The left subtree also contains departures
            // before h.
            //
            // Το αριστερό υποδέντρο περιέχει επίσης
            // αναχωρήσεις πριν από h.
            LatestArrivalBefore(
                node.GetLeft(),
                h,
                ref bestArrival,
                ref found
            );


            // The right subtree may contain more departures
            // before h.
            //
            // Το δεξί υποδέντρο μπορεί να περιέχει και άλλες
            // αναχωρήσεις πριν από h.
            LatestArrivalBefore(
                node.GetRight(),
                h,
                ref bestArrival,
                ref found
            );
        }
        else
        {
            // Current departure is already >= h.
            //
            // Η τρέχουσα αναχώρηση είναι ήδη >= h.
            //
            // Therefore, the right subtree cannot contain
            // a valid flight either.
            //
            // Επομένως το δεξί υποδέντρο δεν μπορεί να περιέχει
            // έγκυρη πτήση.
            LatestArrivalBefore(
                node.GetLeft(),
                h,
                ref bestArrival,
                ref found
            );
        }
    }


    // ========================================================
    // PUBLIC TREE OPERATIONS
    // ========================================================


    // Inserts a new flight.
    // Εισάγει μία νέα πτήση.
    public void Add(Flight flight)
    {
        Node newNode =
            new Node(flight);


        // Empty tree.
        // Άδειο δέντρο.
        if (root == null)
        {
            root = newNode;

            return;
        }


        Node current = root;

        Node parent = null;


        // Find the correct position according to
        // departure time.
        //
        // Βρίσκουμε τη σωστή θέση με βάση
        // την ώρα αναχώρησης.
        while (current != null)
        {
            parent = current;


            if (flight.GetDeparture().IsBefore(
                current.GetData().GetDeparture()))
            {
                current = current.GetLeft();
            }
            else
            {
                current = current.GetRight();
            }
        }


        // Connect the new node to its parent.
        // Συνδέουμε τον νέο κόμβο με τον γονέα του.
        newNode.SetParent(parent);


        if (flight.GetDeparture().IsBefore(
            parent.GetData().GetDeparture()))
        {
            parent.SetLeft(newNode);
        }
        else
        {
            parent.SetRight(newNode);
        }


        // Update MaxArrival values up to the root.
        // Ενημερώνουμε τις τιμές MaxArrival μέχρι τη ρίζα.
        UpdateUpwards(parent);
    }


    // Searches for a flight using its code.
    // Αναζητά μία πτήση χρησιμοποιώντας τον κωδικό της.
    public Node SearchByCode(string code)
    {
        return FindByCode(root, code);
    }


    // Deletes a flight using its code.
    // Διαγράφει μία πτήση χρησιμοποιώντας τον κωδικό της.
    public void RemoveByCode(string code)
    {
        Node node =
            SearchByCode(code);


        if (node == null)
        {
            Console.WriteLine(
                "Flight not found / Η πτήση δεν βρέθηκε.");

            return;
        }


        // Case 1: node has no children.
        // Περίπτωση 1: ο κόμβος δεν έχει παιδιά.
        if (node.GetLeft() == null &&
            node.GetRight() == null)
        {
            RemoveNodeWithAtMostOneChild(node);

            return;
        }


        // Case 2: node has only one child.
        // Περίπτωση 2: ο κόμβος έχει μόνο ένα παιδί.
        if (node.GetLeft() == null ||
            node.GetRight() == null)
        {
            RemoveNodeWithAtMostOneChild(node);

            return;
        }


        // Case 3: node has two children.
        // Περίπτωση 3: ο κόμβος έχει δύο παιδιά.
        //
        // Replace the node's flight with the successor's flight.
        //
        // Αντικαθιστούμε την πτήση του κόμβου
        // με την πτήση του successor.
        Node successor =
            Minimum(node.GetRight());


        node.SetData(
            successor.GetData()
        );


        // The successor has at most one child,
        // so it can now be removed normally.
        //
        // Ο successor έχει το πολύ ένα παιδί,
        // επομένως μπορούμε τώρα να τον διαγράψουμε κανονικά.
        RemoveNodeWithAtMostOneChild(successor);
    }


    // Displays the tree in sorted order.
    // Εμφανίζει το δέντρο σε ταξινομημένη σειρά
    // ως προς την ώρα αναχώρησης.
    public void Display()
    {
        if (root == null)
        {
            Console.WriteLine(
                "Tree is empty / Το δέντρο είναι άδειο.");

            return;
        }


        DisplayInOrder(root);
    }


    // Operation 2:
    // Finds one flight active during a time interval.
    //
    // Λειτουργία 2:
    // Βρίσκει μία πτήση που βρίσκεται σε εξέλιξη
    // μέσα σε ένα χρονικό διάστημα.
    public void FindOne(Time start, Time end)
    {
        Node result =
            FindOneInInterval(
                root,
                start,
                end
            );


        if (result == null)
        {
            Console.WriteLine(
                "No flight found / Δεν βρέθηκε πτήση.");

            return;
        }


        Console.WriteLine(
            "Flight found / Βρέθηκε πτήση:");

        result.GetData().Display();
    }


    // Operation 3:
    // Finds all flights active during a time interval.
    //
    // Λειτουργία 3:
    // Βρίσκει όλες τις πτήσεις που βρίσκονται σε εξέλιξη
    // μέσα σε ένα χρονικό διάστημα.
    public void FindAll(Time start, Time end)
    {
        Console.WriteLine(
            "Flights in progress / Πτήσεις σε εξέλιξη:");

        FindAllInInterval(
            root,
            start,
            end
        );
    }


    // Operation 4:
    // Finds the latest arrival among flights
    // that departed before time h.
    //
    // Λειτουργία 4:
    // Βρίσκει τη μεγαλύτερη ώρα άφιξης μεταξύ
    // των πτήσεων που αναχώρησαν πριν από την ώρα h.
    public void FindLatestArrivalBefore(Time h)
    {
        Time bestArrival = new Time();

        bool found = false;


        LatestArrivalBefore(
            root,
            h,
            ref bestArrival,
            ref found
        );


        if (!found)
        {
            Console.WriteLine(
                "No flight found / Δεν βρέθηκε πτήση.");

            return;
        }


        Console.WriteLine(
            $"Latest arrival: {bestArrival}");
    }
}



// ============================================================
// MAIN
// ============================================================

public class Program
{
    public static void Main()
    {
        Tree flightTree = new Tree();


        // ========================================================
        // Insert the flights from the assignment example.
        //
        // Εισάγουμε τις πτήσεις από το παράδειγμα της εκφώνησης.
        // ========================================================

        flightTree.Add(
            new Flight(
                "OA345",
                new Time(12, 0),
                new Time(13, 0)
            )
        );

        flightTree.Add(
            new Flight(
                "BA123",
                new Time(9, 0),
                new Time(11, 0)
            )
        );

        flightTree.Add(
            new Flight(
                "BA834",
                new Time(16, 0),
                new Time(17, 0)
            )
        );

        flightTree.Add(
            new Flight(
                "SW489",
                new Time(7, 0),
                new Time(14, 0)
            )
        );

        flightTree.Add(
            new Flight(
                "AG879",
                new Time(10, 0),
                new Time(12, 0)
            )
        );

        flightTree.Add(
            new Flight(
                "UA987",
                new Time(14, 0),
                new Time(18, 0)
            )
        );

        flightTree.Add(
            new Flight(
                "OA745",
                new Time(19, 0),
                new Time(21, 0)
            )
        );

        flightTree.Add(
            new Flight(
                "BA854",
                new Time(6, 0),
                new Time(12, 0)
            )
        );

        flightTree.Add(
            new Flight(
                "OA109",
                new Time(8, 0),
                new Time(16, 30)
            )
        );

        flightTree.Add(
            new Flight(
                "CA863",
                new Time(11, 0),
                new Time(13, 30)
            )
        );

        flightTree.Add(
            new Flight(
                "BA111",
                new Time(18, 0),
                new Time(20, 0)
            )
        );


        // ========================================================
        // Display the complete tree.
        //
        // Εμφανίζουμε ολόκληρο το δέντρο.
        // ========================================================

        Console.WriteLine();
        Console.WriteLine("========================================");
        Console.WriteLine("FLIGHT TREE");
        Console.WriteLine("========================================");

        flightTree.Display();


        // ========================================================
        // Operation 2
        //
        // Query interval: [12:00, 14:00]
        //
        // Λειτουργία 2
        //
        // Χρονικό διάστημα: [12:00, 14:00]
        // ========================================================

        Console.WriteLine();
        Console.WriteLine("========================================");
        Console.WriteLine("ONE FLIGHT IN INTERVAL [12:00, 14:00]");
        Console.WriteLine("========================================");

        flightTree.FindOne(
            new Time(12, 0),
            new Time(14, 0)
        );


        // ========================================================
        // Operation 3
        //
        // Find all flights in [12:00, 14:00].
        //
        // Λειτουργία 3
        //
        // Βρίσκουμε όλες τις πτήσεις στο [12:00, 14:00].
        // ========================================================

        Console.WriteLine();
        Console.WriteLine("========================================");
        Console.WriteLine("ALL FLIGHTS IN [12:00, 14:00]");
        Console.WriteLine("========================================");

        flightTree.FindAll(
            new Time(12, 0),
            new Time(14, 0)
        );


        // ========================================================
        // Operation 4
        //
        // h = 11:30
        //
        // Λειτουργία 4
        //
        // h = 11:30
        // ========================================================

        Console.WriteLine();
        Console.WriteLine("========================================");
        Console.WriteLine("LATEST ARRIVAL BEFORE 11:30");
        Console.WriteLine("========================================");

        flightTree.FindLatestArrivalBefore(
            new Time(11, 30)
        );
    }
}