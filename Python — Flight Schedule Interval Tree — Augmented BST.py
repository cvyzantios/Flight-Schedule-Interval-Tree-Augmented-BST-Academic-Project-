# ============================================================
# TIME
# ============================================================

# Stores a time using hours and minutes.
# Αποθηκεύει μία ώρα χρησιμοποιώντας ώρες και λεπτά.
class Time:

    # Constructor.
    # Κατασκευαστής.
    def __init__(self, hour=0, minute=0):
        self.hour = hour
        self.minute = minute


    # Converts the time to total minutes.
    # Μετατρέπει την ώρα σε συνολικά λεπτά.
    #
    # This makes time comparisons much easier.
    # Αυτό κάνει πολύ ευκολότερες τις συγκρίσεις μεταξύ ωρών.
    def to_minutes(self):
        return self.hour * 60 + self.minute


    # Checks whether this time is before another time.
    # Ελέγχει αν αυτή η ώρα είναι πριν από μία άλλη ώρα.
    def is_before(self, other):
        return self.to_minutes() < other.to_minutes()


    # Checks whether this time is after another time.
    # Ελέγχει αν αυτή η ώρα είναι μετά από μία άλλη ώρα.
    def is_after(self, other):
        return self.to_minutes() > other.to_minutes()


    # Checks whether this time is before or equal to another time.
    # Ελέγχει αν αυτή η ώρα είναι πριν ή ίση με μία άλλη.
    def is_before_or_equal(self, other):
        return self.to_minutes() <= other.to_minutes()


    # Checks whether this time is after or equal to another time.
    # Ελέγχει αν αυτή η ώρα είναι μετά ή ίση με μία άλλη.
    def is_after_or_equal(self, other):
        return self.to_minutes() >= other.to_minutes()


    # Checks whether two times are equal.
    # Ελέγχει αν δύο ώρες είναι ίσες.
    def is_equal(self, other):
        return self.to_minutes() == other.to_minutes()


    # Returns the time in HH:MM format.
    # Επιστρέφει την ώρα στη μορφή HH:MM.
    def __str__(self):
        return f"{self.hour:02d}:{self.minute:02d}"



# ============================================================
# FLIGHT
# ============================================================

# Stores all information about one flight.
# Αποθηκεύει όλες τις πληροφορίες για μία πτήση.
class Flight:

    # Constructor.
    # Κατασκευαστής.
    def __init__(self, code="", departure=None, arrival=None):

        self.flight_code = code

        self.departure = (
            departure if departure is not None else Time()
        )

        self.arrival = (
            arrival if arrival is not None else Time()
        )


    # Returns the flight code.
    # Επιστρέφει τον κωδικό της πτήσης.
    def get_flight_code(self):
        return self.flight_code


    # Returns the departure time.
    # Επιστρέφει την ώρα αναχώρησης.
    def get_departure(self):
        return self.departure


    # Returns the arrival time.
    # Επιστρέφει την ώρα άφιξης.
    def get_arrival(self):
        return self.arrival


    # Displays the flight information.
    # Εμφανίζει τις πληροφορίες της πτήσης.
    def display(self):

        print(
            f"{self.flight_code} | "
            f"Departure: {self.departure} | "
            f"Arrival: {self.arrival}"
        )



# ============================================================
# NODE
# ============================================================

# One node of the Binary Search Tree.
# Ένας κόμβος του Δυαδικού Δέντρου Αναζήτησης.
class Node:

    # Constructor.
    # Κατασκευαστής.
    def __init__(self, flight):

        self.data = flight

        self.left = None

        self.right = None

        self.parent = None


        # Maximum arrival time inside this node's subtree.
        # Η μέγιστη ώρα άφιξης μέσα στο υποδέντρο αυτού του κόμβου.
        #
        # Initially, it is the arrival time of the current flight.
        #
        # Αρχικά, είναι η ώρα άφιξης της τρέχουσας πτήσης.
        self.max_arrival = flight.get_arrival()



# ============================================================
# TREE
# ============================================================

# Binary Search Tree for airline flights.
# Δυαδικό Δέντρο Αναζήτησης για πτήσεις.
#
# The tree is ordered by departure time.
# Το δέντρο ταξινομείται με βάση την ώρα αναχώρησης.
class Tree:

    # Constructor.
    # Κατασκευαστής.
    def __init__(self):

        self.root = None


    # Returns the maximum of two times.
    # Επιστρέφει τη μεγαλύτερη από δύο ώρες.
    def maximum(self, a, b):

        if a.is_after(b):
            return a

        return b


    # Updates the MaxArrival value of one node.
    # Ενημερώνει την τιμή MaxArrival ενός κόμβου.
    def update_max_arrival(self, node):

        if node is None:
            return


        # Start with the arrival time of the current flight.
        # Ξεκινάμε με την ώρα άφιξης της τρέχουσας πτήσης.
        maximum_arrival = node.data.get_arrival()


        # Check the left subtree.
        # Ελέγχουμε το αριστερό υποδέντρο.
        if node.left is not None:

            maximum_arrival = self.maximum(
                maximum_arrival,
                node.left.max_arrival
            )


        # Check the right subtree.
        # Ελέγχουμε το δεξί υποδέντρο.
        if node.right is not None:

            maximum_arrival = self.maximum(
                maximum_arrival,
                node.right.max_arrival
            )


        node.max_arrival = maximum_arrival


    # Updates MaxArrival from a node up to the root.
    # Ενημερώνει το MaxArrival από έναν κόμβο μέχρι τη ρίζα.
    def update_upwards(self, node):

        while node is not None:

            self.update_max_arrival(node)

            node = node.parent


    # Finds a flight by its code.
    # Βρίσκει μία πτήση με βάση τον κωδικό της.
    def find_by_code(self, node, code):

        if node is None:
            return None


        if node.data.get_flight_code() == code:
            return node


        result = self.find_by_code(
            node.left,
            code
        )


        if result is not None:
            return result


        return self.find_by_code(
            node.right,
            code
        )


    # Finds the node with the smallest departure time
    # in a subtree.
    #
    # Βρίσκει τον κόμβο με τη μικρότερη ώρα αναχώρησης
    # μέσα σε ένα υποδέντρο.
    def minimum(self, node):

        while node is not None and node.left is not None:

            node = node.left

        return node


    # Removes a node that has at most one child.
    # Διαγράφει έναν κόμβο που έχει το πολύ ένα παιδί.
    def remove_node_with_at_most_one_child(self, node):

        child = None


        if node.left is not None:
            child = node.left
        else:
            child = node.right


        parent = node.parent


        # If the node is the root.
        # Αν ο κόμβος είναι η ρίζα.
        if parent is None:

            self.root = child

            if child is not None:
                child.parent = None


        else:

            # Connect the child to the parent.
            # Συνδέουμε το παιδί με τον γονέα.

            if parent.left == node:
                parent.left = child
            else:
                parent.right = child


            if child is not None:
                child.parent = parent


            # The subtree has changed.
            # Το υποδέντρο έχει αλλάξει.
            self.update_upwards(parent)


        # Python automatically handles unused objects.
        # Η Python διαχειρίζεται αυτόματα αντικείμενα
        # που δεν χρησιμοποιούνται πλέον.


    # Recursive function for displaying the tree.
    # Αναδρομική συνάρτηση για την εμφάνιση του δέντρου.
    def display_in_order(self, node):

        if node is None:
            return


        self.display_in_order(node.left)


        print("----------------------------------------")

        node.data.display()

        print(
            f"Max Arrival in subtree: "
            f"{node.max_arrival}"
        )


        self.display_in_order(node.right)


    # Searches for one flight in a time interval.
    # Αναζητά μία πτήση που βρίσκεται σε εξέλιξη
    # μέσα σε ένα χρονικό διάστημα.
    def find_one_in_interval(
        self,
        node,
        start,
        end
    ):

        if node is None:
            return None


        # The current flight is active during the interval
        # if the two intervals overlap.
        #
        # Η τρέχουσα πτήση βρίσκεται σε εξέλιξη αν
        # τα δύο χρονικά διαστήματα επικαλύπτονται.
        #
        # departure <= end AND arrival >= start
        #
        # αναχώρηση <= τέλος ΚΑΙ άφιξη >= αρχή.
        if (
            node.data.get_departure().is_before_or_equal(end)
            and
            node.data.get_arrival().is_after_or_equal(start)
        ):

            return node


        # Search left subtree only if it may contain
        # a relevant flight.
        #
        # Εξετάζουμε το αριστερό υποδέντρο μόνο αν μπορεί
        # να περιέχει σχετική πτήση.
        if (
            node.left is not None
            and
            node.left.max_arrival.is_after_or_equal(start)
        ):

            result = self.find_one_in_interval(
                node.left,
                start,
                end
            )


            if result is not None:
                return result


        # Search right subtree if departures can still
        # be relevant.
        #
        # Εξετάζουμε το δεξί υποδέντρο αν οι αναχωρήσεις
        # μπορούν ακόμη να σχετίζονται με το διάστημα.
        if (
            node.right is not None
            and
            node.data.get_departure().is_before_or_equal(end)
        ):

            return self.find_one_in_interval(
                node.right,
                start,
                end
            )


        return None


    # Finds all flights active during an interval.
    # Βρίσκει όλες τις πτήσεις που βρίσκονται σε εξέλιξη
    # μέσα σε ένα χρονικό διάστημα.
    def find_all_in_interval(
        self,
        node,
        start,
        end
    ):

        if node is None:
            return


        # Search left subtree only if it may contain
        # a relevant flight.
        #
        # Εξετάζουμε το αριστερό υποδέντρο μόνο αν μπορεί
        # να περιέχει σχετική πτήση.
        if (
            node.left is not None
            and
            node.left.max_arrival.is_after_or_equal(start)
        ):

            self.find_all_in_interval(
                node.left,
                start,
                end
            )


        # Check current flight.
        # Ελέγχουμε την τρέχουσα πτήση.
        if (
            node.data.get_departure().is_before_or_equal(end)
            and
            node.data.get_arrival().is_after_or_equal(start)
        ):

            node.data.display()


        # Search right subtree if its departures can still
        # be relevant.
        #
        # Εξετάζουμε το δεξί υποδέντρο αν οι αναχωρήσεις του
        # μπορούν ακόμη να σχετίζονται με το διάστημα.
        if (
            node.right is not None
            and
            node.data.get_departure().is_before_or_equal(end)
        ):

            self.find_all_in_interval(
                node.right,
                start,
                end
            )


    # Returns the latest arrival among flights
    # that departed before a specified time.
    #
    # Επιστρέφει τη μεγαλύτερη ώρα άφιξης μεταξύ των πτήσεων
    # που αναχώρησαν πριν από μία συγκεκριμένη ώρα.
    def latest_arrival_before(
        self,
        node,
        h,
        best_arrival,
        found
    ):

        if node is None:
            return


        if node.data.get_departure().is_before(h):

            # The current flight qualifies.
            # Η τρέχουσα πτήση πληροί την προϋπόθεση.
            if (
                not found[0]
                or
                node.data.get_arrival().is_after(best_arrival[0])
            ):

                best_arrival[0] = node.data.get_arrival()

                found[0] = True


            # The left subtree also contains departures
            # before h.
            #
            # Το αριστερό υποδέντρο περιέχει επίσης
            # αναχωρήσεις πριν από h.
            self.latest_arrival_before(
                node.left,
                h,
                best_arrival,
                found
            )


            # The right subtree may contain more departures
            # before h.
            #
            # Το δεξί υποδέντρο μπορεί να περιέχει και άλλες
            # αναχωρήσεις πριν από h.
            self.latest_arrival_before(
                node.right,
                h,
                best_arrival,
                found
            )


        else:

            # Current departure is already >= h.
            #
            # Η τρέχουσα αναχώρηση είναι ήδη >= h.
            #
            # Therefore, the right subtree cannot contain
            # a valid flight.
            #
            # Επομένως το δεξί υποδέντρο δεν μπορεί να περιέχει
            # έγκυρη πτήση.
            self.latest_arrival_before(
                node.left,
                h,
                best_arrival,
                found
            )


    # ========================================================
    # PUBLIC TREE OPERATIONS
    # ========================================================


    # Inserts a new flight.
    # Εισάγει μία νέα πτήση.
    def add(self, flight):

        new_node = Node(flight)


        # Empty tree.
        # Άδειο δέντρο.
        if self.root is None:

            self.root = new_node

            return


        current = self.root

        parent = None


        # Find the correct position according to
        # departure time.
        #
        # Βρίσκουμε τη σωστή θέση με βάση
        # την ώρα αναχώρησης.
        while current is not None:

            parent = current


            if (
                flight.get_departure().is_before(
                    current.data.get_departure()
                )
            ):

                current = current.left

            else:

                current = current.right


        # Connect the new node to its parent.
        # Συνδέουμε τον νέο κόμβο με τον γονέα του.
        new_node.parent = parent


        if (
            flight.get_departure().is_before(
                parent.data.get_departure()
            )
        ):

            parent.left = new_node

        else:

            parent.right = new_node


        # Update MaxArrival values up to the root.
        # Ενημερώνουμε τις τιμές MaxArrival μέχρι τη ρίζα.
        self.update_upwards(parent)


    # Searches for a flight using its code.
    # Αναζητά μία πτήση χρησιμοποιώντας τον κωδικό της.
    def search_by_code(self, code):

        return self.find_by_code(
            self.root,
            code
        )


    # Deletes a flight using its code.
    # Διαγράφει μία πτήση χρησιμοποιώντας τον κωδικό της.
    def remove_by_code(self, code):

        node = self.search_by_code(code)


        if node is None:

            print(
                "Flight not found / Η πτήση δεν βρέθηκε."
            )

            return


        # Case 1: node has no children.
        # Περίπτωση 1: ο κόμβος δεν έχει παιδιά.
        if (
            node.left is None
            and
            node.right is None
        ):

            self.remove_node_with_at_most_one_child(node)

            return


        # Case 2: node has only one child.
        # Περίπτωση 2: ο κόμβος έχει μόνο ένα παιδί.
        if (
            node.left is None
            or
            node.right is None
        ):

            self.remove_node_with_at_most_one_child(node)

            return


        # Case 3: node has two children.
        # Περίπτωση 3: ο κόμβος έχει δύο παιδιά.
        #
        # Replace the node's flight with the successor's flight.
        #
        # Αντικαθιστούμε την πτήση του κόμβου
        # με την πτήση του successor.
        successor = self.minimum(node.right)


        node.data = successor.data


        # The successor has at most one child,
        # so it can now be removed normally.
        #
        # Ο successor έχει το πολύ ένα παιδί,
        # επομένως μπορούμε τώρα να τον διαγράψουμε κανονικά.
        self.remove_node_with_at_most_one_child(successor)


    # Displays the tree in sorted order.
    # Εμφανίζει το δέντρο σε ταξινομημένη σειρά
    # ως προς την ώρα αναχώρησης.
    def display(self):

        if self.root is None:

            print(
                "Tree is empty / Το δέντρο είναι άδειο."
            )

            return


        self.display_in_order(self.root)


    # Operation 2:
    # Finds one flight active during a time interval.
    #
    # Λειτουργία 2:
    # Βρίσκει μία πτήση που βρίσκεται σε εξέλιξη
    # μέσα σε ένα χρονικό διάστημα.
    def find_one(self, start, end):

        result = self.find_one_in_interval(
            self.root,
            start,
            end
        )


        if result is None:

            print(
                "No flight found / Δεν βρέθηκε πτήση."
            )

            return


        print(
            "Flight found / Βρέθηκε πτήση:"
        )

        result.data.display()


    # Operation 3:
    # Finds all flights active during an interval.
    #
    # Λειτουργία 3:
    # Βρίσκει όλες τις πτήσεις που βρίσκονται σε εξέλιξη
    # μέσα σε ένα χρονικό διάστημα.
    def find_all(self, start, end):

        print(
            "Flights in progress / Πτήσεις σε εξέλιξη:"
        )

        self.find_all_in_interval(
            self.root,
            start,
            end
        )


    # Operation 4:
    # Finds the latest arrival among flights
    # that departed before time h.
    #
    # Λειτουργία 4:
    # Βρίσκει τη μεγαλύτερη ώρα άφιξης μεταξύ
    # των πτήσεων που αναχώρησαν πριν από την ώρα h.
    def find_latest_arrival_before(self, h):

        best_arrival = [Time()]

        found = [False]


        self.latest_arrival_before(
            self.root,
            h,
            best_arrival,
            found
        )


        if not found[0]:

            print(
                "No flight found / Δεν βρέθηκε πτήση."
            )

            return


        print(
            f"Latest arrival: {best_arrival[0]}"
        )



# ============================================================
# MAIN
# ============================================================

if __name__ == "__main__":

    flight_tree = Tree()


    # ========================================================
    # Insert the flights from the assignment example.
    #
    # Εισάγουμε τις πτήσεις από το παράδειγμα της εκφώνησης.
    # ========================================================

    flight_tree.add(
        Flight(
            "OA345",
            Time(12, 0),
            Time(13, 0)
        )
    )

    flight_tree.add(
        Flight(
            "BA123",
            Time(9, 0),
            Time(11, 0)
        )
    )

    flight_tree.add(
        Flight(
            "BA834",
            Time(16, 0),
            Time(17, 0)
        )
    )

    flight_tree.add(
        Flight(
            "SW489",
            Time(7, 0),
            Time(14, 0)
        )
    )

    flight_tree.add(
        Flight(
            "AG879",
            Time(10, 0),
            Time(12, 0)
        )
    )

    flight_tree.add(
        Flight(
            "UA987",
            Time(14, 0),
            Time(18, 0)
        )
    )

    flight_tree.add(
        Flight(
            "OA745",
            Time(19, 0),
            Time(21, 0)
        )
    )

    flight_tree.add(
        Flight(
            "BA854",
            Time(6, 0),
            Time(12, 0)
        )
    )

    flight_tree.add(
        Flight(
            "OA109",
            Time(8, 0),
            Time(16, 30)
        )
    )

    flight_tree.add(
        Flight(
            "CA863",
            Time(11, 0),
            Time(13, 30)
        )
    )

    flight_tree.add(
        Flight(
            "BA111",
            Time(18, 0),
            Time(20, 0)
        )
    )


    # ========================================================
    # Display the complete tree.
    #
    # Εμφανίζουμε ολόκληρο το δέντρο.
    # ========================================================

    print()
    print("========================================")
    print("FLIGHT TREE")
    print("========================================")

    flight_tree.display()


    # ========================================================
    # Operation 2
    #
    # Query interval: [12:00, 14:00]
    #
    # Λειτουργία 2
    #
    # Χρονικό διάστημα: [12:00, 14:00]
    # ========================================================

    print()
    print("========================================")
    print("ONE FLIGHT IN INTERVAL [12:00, 14:00]")
    print("========================================")

    flight_tree.find_one(
        Time(12, 0),
        Time(14, 0)
    )


    # ========================================================
    # Operation 3
    #
    # Find all flights in [12:00, 14:00].
    #
    # Λειτουργία 3
    #
    # Βρίσκουμε όλες τις πτήσεις στο [12:00, 14:00].
    # ========================================================

    print()
    print("========================================")
    print("ALL FLIGHTS IN [12:00, 14:00]")
    print("========================================")

    flight_tree.find_all(
        Time(12, 0),
        Time(14, 0)
    )


    # ========================================================
    # Operation 4
    #
    # h = 11:30
    #
    # Λειτουργία 4
    #
    # h = 11:30
    # ========================================================

    print()
    print("========================================")
    print("LATEST ARRIVAL BEFORE 11:30")
    print("========================================")

    flight_tree.find_latest_arrival_before(
        Time(11, 30)
    )