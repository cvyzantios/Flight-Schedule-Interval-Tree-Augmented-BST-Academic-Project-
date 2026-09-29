#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


// ============================================================
// TIME
// ============================================================

// Stores a time using hours and minutes.
// Αποθηκεύει μία ώρα χρησιμοποιώντας ώρες και λεπτά.
struct Time
{
    int hour;
    int minute;


    // Constructor.
    // Κατασκευαστής.
    Time(int h = 0, int m = 0)
    {
        hour = h;
        minute = m;
    }


    // Converts the time to total minutes.
    // Μετατρέπει την ώρα σε συνολικά λεπτά.
    //
    // This makes time comparisons much easier.
    // Αυτό κάνει πολύ ευκολότερες τις συγκρίσεις μεταξύ ωρών.
    int toMinutes() const
    {
        return hour * 60 + minute;
    }


    // Checks whether this time is before another time.
    // Ελέγχει αν αυτή η ώρα είναι πριν από μία άλλη ώρα.
    bool operator<(const Time& other) const
    {
        return toMinutes() < other.toMinutes();
    }


    // Checks whether this time is after another time.
    // Ελέγχει αν αυτή η ώρα είναι μετά από μία άλλη ώρα.
    bool operator>(const Time& other) const
    {
        return toMinutes() > other.toMinutes();
    }


    // Checks whether two times are equal.
    // Ελέγχει αν δύο ώρες είναι ίσες.
    bool operator==(const Time& other) const
    {
        return toMinutes() == other.toMinutes();
    }


    // Checks whether this time is before or equal to another time.
    // Ελέγχει αν αυτή η ώρα είναι πριν ή ίση με μία άλλη.
    bool operator<=(const Time& other) const
    {
        return toMinutes() <= other.toMinutes();
    }


    // Checks whether this time is after or equal to another time.
    // Ελέγχει αν αυτή η ώρα είναι μετά ή ίση με μία άλλη.
    bool operator>=(const Time& other) const
    {
        return toMinutes() >= other.toMinutes();
    }
};


// Prints a time in HH:MM format.
// Εκτυπώνει μία ώρα στη μορφή HH:MM.
ostream& operator<<(ostream& out, const Time& time)
{
    out << setfill('0')
        << setw(2) << time.hour
        << ":"
        << setw(2) << time.minute
        << setfill(' ');

    return out;
}



// ============================================================
// FLIGHT
// ============================================================

// Stores all information about one flight.
// Αποθηκεύει όλες τις πληροφορίες για μία πτήση.
class Flight
{
private:

    string flightCode;

    Time departure;

    Time arrival;


public:

    // Constructor.
    // Κατασκευαστής.
    Flight(
        string code = "",
        Time dep = Time(),
        Time arr = Time()
    )
    {
        flightCode = code;
        departure = dep;
        arrival = arr;
    }


    // Returns the flight code.
    // Επιστρέφει τον κωδικό της πτήσης.
    string getFlightCode() const
    {
        return flightCode;
    }


    // Returns the departure time.
    // Επιστρέφει την ώρα αναχώρησης.
    Time getDeparture() const
    {
        return departure;
    }


    // Returns the arrival time.
    // Επιστρέφει την ώρα άφιξης.
    Time getArrival() const
    {
        return arrival;
    }


    // Displays the flight information.
    // Εμφανίζει τις πληροφορίες της πτήσης.
    void display() const
    {
        cout << flightCode
             << " | Departure: " << departure
             << " | Arrival: " << arrival
             << endl;
    }
};



// ============================================================
// NODE
// ============================================================

// One node of the Binary Search Tree.
// Ένας κόμβος του Δυαδικού Δέντρου Αναζήτησης.
class Node
{
private:

    Flight data;

    Node* left;

    Node* right;

    Node* parent;


    // Maximum arrival time inside this node's subtree.
    // Η μέγιστη ώρα άφιξης μέσα στο υποδέντρο αυτού του κόμβου.
    Time maxArrival;


public:

    // Constructor.
    // Κατασκευαστής.
    Node(const Flight& flight)
    {
        data = flight;

        left = nullptr;

        right = nullptr;

        parent = nullptr;

        // Initially, the maximum arrival is the arrival
        // of the flight stored in this node.
        //
        // Αρχικά, η μέγιστη ώρα άφιξης είναι η ώρα άφιξης
        // της πτήσης που βρίσκεται στον συγκεκριμένο κόμβο.
        maxArrival = flight.getArrival();
    }


    // Returns the flight stored in this node.
    // Επιστρέφει την πτήση που είναι αποθηκευμένη στον κόμβο.
    Flight& getData()
    {
        return data;
    }


    // Returns the left child.
    // Επιστρέφει το αριστερό παιδί.
    Node* getLeft()
    {
        return left;
    }


    // Returns the right child.
    // Επιστρέφει το δεξί παιδί.
    Node* getRight()
    {
        return right;
    }


    // Returns the parent.
    // Επιστρέφει τον γονέα.
    Node* getParent()
    {
        return parent;
    }


    // Returns the maximum arrival time of the subtree.
    // Επιστρέφει τη μέγιστη ώρα άφιξης του υποδέντρου.
    Time getMaxArrival()
    {
        return maxArrival;
    }


    // Sets the left child.
    // Ορίζει το αριστερό παιδί.
    void setLeft(Node* node)
    {
        left = node;
    }


    // Sets the right child.
    // Ορίζει το δεξί παιδί.
    void setRight(Node* node)
    {
        right = node;
    }


    // Sets the parent.
    // Ορίζει τον γονέα.
    void setParent(Node* node)
    {
        parent = node;
    }


    // Sets the maximum arrival time.
    // Ορίζει τη μέγιστη ώρα άφιξης.
    void setMaxArrival(Time time)
    {
        maxArrival = time;
    }
};



// ============================================================
// TREE
// ============================================================

// Binary Search Tree for airline flights.
// Δυαδικό Δέντρο Αναζήτησης για πτήσεις.
//
// The tree is ordered by departure time.
// Το δέντρο ταξινομείται με βάση την ώρα αναχώρησης.
class Tree
{
private:

    Node* root;


    // Returns the maximum of two times.
    // Επιστρέφει τη μεγαλύτερη από δύο ώρες.
    Time maximum(Time a, Time b)
    {
        if (a > b)
            return a;

        return b;
    }


    // Updates the MaxArrival value of one node.
    // Ενημερώνει την τιμή MaxArrival ενός κόμβου.
    void updateMaxArrival(Node* node)
    {
        if (node == nullptr)
            return;


        // Start with the arrival time of the flight
        // stored in the current node.
        //
        // Ξεκινάμε με την ώρα άφιξης της πτήσης
        // που βρίσκεται στον συγκεκριμένο κόμβο.
        Time maximumArrival =
            node->getData().getArrival();


        // Check the left subtree.
        // Ελέγχουμε το αριστερό υποδέντρο.
        if (node->getLeft() != nullptr)
        {
            maximumArrival =
                maximum(
                    maximumArrival,
                    node->getLeft()->getMaxArrival()
                );
        }


        // Check the right subtree.
        // Ελέγχουμε το δεξί υποδέντρο.
        if (node->getRight() != nullptr)
        {
            maximumArrival =
                maximum(
                    maximumArrival,
                    node->getRight()->getMaxArrival()
                );
        }


        node->setMaxArrival(maximumArrival);
    }


    // Updates MaxArrival from a node up to the root.
    // Ενημερώνει το MaxArrival από έναν κόμβο μέχρι τη ρίζα.
    void updateUpwards(Node* node)
    {
        while (node != nullptr)
        {
            updateMaxArrival(node);

            node = node->getParent();
        }
    }


    // Finds a flight by its code.
    // Βρίσκει μία πτήση με βάση τον κωδικό της.
    Node* findByCode(Node* node, const string& code)
    {
        if (node == nullptr)
            return nullptr;


        if (node->getData().getFlightCode() == code)
            return node;


        Node* result =
            findByCode(node->getLeft(), code);


        if (result != nullptr)
            return result;


        return findByCode(node->getRight(), code);
    }


    // Removes a node that has at most one child.
    // Διαγράφει έναν κόμβο που έχει το πολύ ένα παιδί.
    void removeNodeWithAtMostOneChild(Node* node)
    {
        Node* child = nullptr;


        if (node->getLeft() != nullptr)
            child = node->getLeft();

        else
            child = node->getRight();


        Node* parent = node->getParent();


        // If the node is the root.
        // Αν ο κόμβος είναι η ρίζα.
        if (parent == nullptr)
        {
            root = child;

            if (child != nullptr)
                child->setParent(nullptr);
        }

        else
        {
            // Connect the child to the parent.
            // Συνδέουμε το παιδί με τον γονέα.

            if (parent->getLeft() == node)
                parent->setLeft(child);

            else
                parent->setRight(child);


            if (child != nullptr)
                child->setParent(parent);


            // The subtree has changed.
            // Το υποδέντρο έχει αλλάξει.
            updateUpwards(parent);
        }


        delete node;
    }


    // Finds the node with the smallest departure time
    // in a subtree.
    //
    // Βρίσκει τον κόμβο με τη μικρότερη ώρα αναχώρησης
    // μέσα σε ένα υποδέντρο.
    Node* minimum(Node* node)
    {
        while (node != nullptr &&
               node->getLeft() != nullptr)
        {
            node = node->getLeft();
        }

        return node;
    }


    // Recursive function for displaying the tree.
    // Αναδρομική συνάρτηση για την εμφάνιση του δέντρου.
    void displayInOrder(Node* node)
    {
        if (node == nullptr)
            return;


        displayInOrder(node->getLeft());


        cout << "----------------------------------------"
             << endl;

        node->getData().display();

        cout << "Max Arrival in subtree: "
             << node->getMaxArrival()
             << endl;


        displayInOrder(node->getRight());
    }


    // Searches for one flight in a time interval.
    // Αναζητά μία πτήση που βρίσκεται σε εξέλιξη
    // μέσα σε ένα χρονικό διάστημα.
    Node* findOneInInterval(
        Node* node,
        Time start,
        Time end)
    {
        if (node == nullptr)
            return nullptr;


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
        if (node->getData().getDeparture() <= end &&
            node->getData().getArrival() >= start)
        {
            return node;
        }


        // If the maximum arrival time in the left subtree
        // is before the beginning of our interval,
        // no flight in that subtree can be active.
        //
        // Αν η μέγιστη ώρα άφιξης στο αριστερό υποδέντρο
        // είναι πριν από την αρχή του διαστήματος,
        // καμία πτήση εκεί δεν μπορεί να βρίσκεται σε εξέλιξη.
        if (node->getLeft() != nullptr &&
            node->getLeft()->getMaxArrival() >= start)
        {
            Node* result =
                findOneInInterval(
                    node->getLeft(),
                    start,
                    end
                );


            if (result != nullptr)
                return result;
        }


        // Search the right subtree.
        // Αναζητούμε στο δεξί υποδέντρο.
        //
        // We only need to continue if departures can still
        // fall before or inside the query interval.
        //
        // Συνεχίζουμε μόνο αν υπάρχουν αναχωρήσεις που
        // μπορούν να βρίσκονται πριν ή μέσα στο διάστημα.
        if (node->getRight() != nullptr &&
            node->getData().getDeparture() <= end)
        {
            return findOneInInterval(
                node->getRight(),
                start,
                end
            );
        }


        return nullptr;
    }


    // Finds all flights active during an interval.
    // Βρίσκει όλες τις πτήσεις που βρίσκονται σε εξέλιξη
    // μέσα σε ένα χρονικό διάστημα.
    void findAllInInterval(
        Node* node,
        Time start,
        Time end)
    {
        if (node == nullptr)
            return;


        // Search left subtree only if it may contain
        // a flight arriving during/after the interval start.
        //
        // Εξετάζουμε το αριστερό υποδέντρο μόνο αν μπορεί
        // να περιέχει πτήση που φτάνει κατά ή μετά την αρχή.
        if (node->getLeft() != nullptr &&
            node->getLeft()->getMaxArrival() >= start)
        {
            findAllInInterval(
                node->getLeft(),
                start,
                end
            );
        }


        // Check current flight.
        // Ελέγχουμε την τρέχουσα πτήση.
        if (node->getData().getDeparture() <= end &&
            node->getData().getArrival() >= start)
        {
            node->getData().display();
        }


        // Search right subtree if its departures can still
        // be relevant to the query.
        //
        // Εξετάζουμε το δεξί υποδέντρο αν οι αναχωρήσεις του
        // μπορούν ακόμη να σχετίζονται με το διάστημα.
        if (node->getRight() != nullptr &&
            node->getData().getDeparture() <= end)
        {
            findAllInInterval(
                node->getRight(),
                start,
                end
            );
        }
    }


    // Returns the latest arrival among flights that
    // departed before a specified time.
    //
    // Επιστρέφει τη μεγαλύτερη ώρα άφιξης μεταξύ των πτήσεων
    // που αναχώρησαν πριν από μία συγκεκριμένη ώρα.
    void latestArrivalBefore(
        Node* node,
        Time h,
        Time& bestArrival,
        bool& found)
    {
        if (node == nullptr)
            return;


        if (node->getData().getDeparture() < h)
        {
            // The current flight qualifies.
            // Η τρέχουσα πτήση πληροί την προϋπόθεση.
            if (!found ||
                node->getData().getArrival() > bestArrival)
            {
                bestArrival =
                    node->getData().getArrival();

                found = true;
            }


            // Since this node departs before h,
            // its left subtree also contains departures before h.
            //
            // Αφού ο συγκεκριμένος κόμβος αναχωρεί πριν από h,
            // και το αριστερό υποδέντρο περιέχει επίσης
            // αναχωρήσεις πριν από h.
            latestArrivalBefore(
                node->getLeft(),
                h,
                bestArrival,
                found
            );


            // The right subtree may contain more departures
            // before h.
            //
            // Το δεξί υποδέντρο μπορεί να περιέχει και άλλες
            // αναχωρήσεις πριν από h.
            latestArrivalBefore(
                node->getRight(),
                h,
                bestArrival,
                found
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
            latestArrivalBefore(
                node->getLeft(),
                h,
                bestArrival,
                found
            );
        }
    }


public:

    // Constructor.
    // Κατασκευαστής.
    Tree()
    {
        root = nullptr;
    }


    // Returns the root of the tree.
    // Επιστρέφει τη ρίζα του δέντρου.
    Node* getRoot()
    {
        return root;
    }


    // Inserts a new flight.
    // Εισάγει μία νέα πτήση.
    void add(const Flight& flight)
    {
        Node* newNode =
            new Node(flight);


        // Empty tree.
        // Άδειο δέντρο.
        if (root == nullptr)
        {
            root = newNode;

            return;
        }


        Node* current = root;

        Node* parent = nullptr;


        // Find the correct position according to
        // departure time.
        //
        // Βρίσκουμε τη σωστή θέση με βάση
        // την ώρα αναχώρησης.
        while (current != nullptr)
        {
            parent = current;


            if (flight.getDeparture() <
                current->getData().getDeparture())
            {
                current = current->getLeft();
            }
            else
            {
                current = current->getRight();
            }
        }


        // Connect the new node to its parent.
        // Συνδέουμε τον νέο κόμβο με τον γονέα του.
        newNode->setParent(parent);


        if (flight.getDeparture() <
            parent->getData().getDeparture())
        {
            parent->setLeft(newNode);
        }
        else
        {
            parent->setRight(newNode);
        }


        // The insertion may have changed MaxArrival
        // values all the way to the root.
        //
        // Η εισαγωγή μπορεί να άλλαξε τις τιμές MaxArrival
        // μέχρι και τη ρίζα.
        updateUpwards(parent);
    }


    // Searches for a flight using its code.
    // Αναζητά μία πτήση χρησιμοποιώντας τον κωδικό της.
    Node* searchByCode(const string& code)
    {
        return findByCode(root, code);
    }


    // Deletes a flight using its code.
    // Διαγράφει μία πτήση χρησιμοποιώντας τον κωδικό της.
    void removeByCode(const string& code)
    {
        Node* node = searchByCode(code);


        if (node == nullptr)
        {
            cout << "Flight not found / Η πτήση δεν βρέθηκε."
                 << endl;

            return;
        }


        // Case 1: node has no children.
        // Περίπτωση 1: ο κόμβος δεν έχει παιδιά.
        if (node->getLeft() == nullptr &&
            node->getRight() == nullptr)
        {
            removeNodeWithAtMostOneChild(node);

            return;
        }


        // Case 2: node has only one child.
        // Περίπτωση 2: ο κόμβος έχει μόνο ένα παιδί.
        if (node->getLeft() == nullptr ||
            node->getRight() == nullptr)
        {
            removeNodeWithAtMostOneChild(node);

            return;
        }


        // Case 3: node has two children.
        // Περίπτωση 3: ο κόμβος έχει δύο παιδιά.
        //
        // We replace the node's flight with the successor's flight.
        //
        // Αντικαθιστούμε τα στοιχεία του κόμβου
        // με τα στοιχεία του successor.
        Node* successor =
            minimum(node->getRight());


        node->getData() =
            successor->getData();


        // The successor has at most one child,
        // so it can now be removed normally.
        //
        // Ο successor έχει το πολύ ένα παιδί,
        // επομένως μπορούμε τώρα να τον διαγράψουμε κανονικά.
        removeNodeWithAtMostOneChild(successor);
    }


    // Displays the tree in sorted order.
    // Εμφανίζει το δέντρο σε ταξινομημένη σειρά
    // ως προς την ώρα αναχώρησης.
    void display()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty / Το δέντρο είναι άδειο."
                 << endl;

            return;
        }


        displayInOrder(root);
    }


    // Operation 2:
    // Finds one flight active during a time interval.
    //
    // Λειτουργία 2:
    // Βρίσκει μία πτήση που βρίσκεται σε εξέλιξη
    // μέσα σε ένα χρονικό διάστημα.
    void findOne(Time start, Time end)
    {
        Node* result =
            findOneInInterval(
                root,
                start,
                end
            );


        if (result == nullptr)
        {
            cout << "No flight found / Δεν βρέθηκε πτήση."
                 << endl;

            return;
        }


        cout << "Flight found / Βρέθηκε πτήση:"
             << endl;

        result->getData().display();
    }


    // Operation 3:
    // Finds all flights active during a time interval.
    //
    // Λειτουργία 3:
    // Βρίσκει όλες τις πτήσεις που βρίσκονται σε εξέλιξη
    // μέσα σε ένα χρονικό διάστημα.
    void findAll(Time start, Time end)
    {
        cout << "Flights in progress / Πτήσεις σε εξέλιξη:"
             << endl;

        findAllInInterval(
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
    void latestArrivalBefore(Time h)
    {
        Time bestArrival;

        bool found = false;


        latestArrivalBefore(
            root,
            h,
            bestArrival,
            found
        );


        if (!found)
        {
            cout << "No flight found / Δεν βρέθηκε πτήση."
                 << endl;

            return;
        }


        cout << "Latest arrival: "
             << bestArrival
             << endl;
    }
};



// ============================================================
// MAIN
// ============================================================

int main()
{
    Tree flightTree;


    // ========================================================
    // Insert the flights from the assignment example.
    //
    // Εισάγουμε τις πτήσεις από το παράδειγμα της εκφώνησης.
    // ========================================================

    flightTree.add(
        Flight("OA345", Time(12, 0), Time(13, 0))
    );

    flightTree.add(
        Flight("BA123", Time(9, 0), Time(11, 0))
    );

    flightTree.add(
        Flight("BA834", Time(16, 0), Time(17, 0))
    );

    flightTree.add(
        Flight("SW489", Time(7, 0), Time(14, 0))
    );

    flightTree.add(
        Flight("AG879", Time(10, 0), Time(12, 0))
    );

    flightTree.add(
        Flight("UA987", Time(14, 0), Time(18, 0))
    );

    flightTree.add(
        Flight("OA745", Time(19, 0), Time(21, 0))
    );

    flightTree.add(
        Flight("BA854", Time(6, 0), Time(12, 0))
    );

    flightTree.add(
        Flight("OA109", Time(8, 0), Time(16, 30))
    );

    flightTree.add(
        Flight("CA863", Time(11, 0), Time(13, 30))
    );

    flightTree.add(
        Flight("BA111", Time(18, 0), Time(20, 0))
    );


    // ========================================================
    // Display the complete tree.
    //
    // Εμφανίζουμε ολόκληρο το δέντρο.
    // ========================================================

    cout << endl;
    cout << "========================================"
         << endl;

    cout << "FLIGHT TREE"
         << endl;

    cout << "========================================"
         << endl;

    flightTree.display();


    // ========================================================
    // Operation 2
    //
    // Query interval: [12:00, 14:00]
    //
    // Λειτουργία 2
    //
    // Χρονικό διάστημα: [12:00, 14:00]
    // ========================================================

    cout << endl;

    cout << "========================================"
         << endl;

    cout << "ONE FLIGHT IN INTERVAL [12:00, 14:00]"
         << endl;

    cout << "========================================"
         << endl;

    flightTree.findOne(
        Time(12, 0),
        Time(14, 0)
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

    cout << endl;

    cout << "========================================"
         << endl;

    cout << "ALL FLIGHTS IN [12:00, 14:00]"
         << endl;

    cout << "========================================"
         << endl;

    flightTree.findAll(
        Time(12, 0),
        Time(14, 0)
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

    cout << endl;

    cout << "========================================"
         << endl;

    cout << "LATEST ARRIVAL BEFORE 11:30"
         << endl;

    cout << "========================================"
         << endl;

    flightTree.latestArrivalBefore(
        Time(11, 30)
    );


    return 0;
}