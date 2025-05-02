#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define BOX_WIDTH 140
#define MAX_SEATS 100

// Color codes for terminal output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

// Structure to store seat information
typedef struct {
    int day;        // Travel day
    int month;      // Travel month
    int year;       // Travel year
    int total_seats; // Total available seats
    int w_list;     // Waitlist count
    int c_b_status; // Cancellation/booking status
    int array_seat_status; // Seat status array
} SEAT;

// Structure to store booking information
typedef struct {
    char username[50];  // User who booked
    char name[50];      // Passenger name
    int train_number;   // Train number
    char train_name[50]; // Train name
    int day, month, year; // Travel date
    int seat_number;    // Allocated seat
} BOOKING;

// Structure to store train information
typedef struct train_node {
    int train_number;           // Unique train ID
    char *train_name;           // Train name
    char *source;               // Departure station
    char *dest;                 // Destination station
    struct train_node *link;    // Next train in list
    SEAT *train;                // Seat availability info
} TRAIN;

// Function prototypes
void print_line(char c, int length);
void print_header(const char *title, const char *color);
void print_train_row(TRAIN *train);
void print_booking_details(BOOKING *b, TRAIN *info);
int check_password(char *str);
char *get_string();
void print_train_info(TRAIN *info);
TRAIN* add_trains(TRAIN *info);
void save_file(TRAIN *info);
TRAIN *syn_file(TRAIN *info);
void syn_file1(TRAIN *info);
void reserve_ticket(TRAIN *info, char *username);
void cancel_ticket(TRAIN *info, char *username);
void book_ticket(TRAIN *info, char *username);
void sign_up(void);
int sign_in(TRAIN *info);
void user_menu(TRAIN *info, char *username);
void admin_menu(TRAIN **info);