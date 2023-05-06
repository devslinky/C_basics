#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

/* DO NOT EDIT THE LINES BELOW */
#define STRING_MAX 1024

typedef struct node {
	char *name;
	int lines;
	int runtime;
	int memory_usage;

	struct node *next;
} Node;

typedef struct linked_list {
	Node *head;
} LinkedList;

void readInputString(char *, int);
void readInputNumber(int *);
void readInputChar(char *);

LinkedList * newList();
char getCommand();

void handleInsert(LinkedList *);
void handleDelete(LinkedList *);
void handleSearch(LinkedList *);
void handlePrint(LinkedList *);
void handleQuit(LinkedList *);

int main() {
	LinkedList *list = newList();
	char command = '\0';

	printf("Experimental database entry\n");

	while (command != 'Q') {
		command = getCommand();

		switch (command) {
			case 'I':
				handleInsert(list);
				break;
			case 'D':
				handleDelete(list);
				break;
			case 'S':
				handleSearch(list);
				break;
			case 'P':
				handlePrint(list);
				break;
			case 'Q':
				handleQuit(list);
				break;
		}
	}



	free(list);
	return 0;
}
/* DO NOT EDIT THE LINES ABOVE */

char *name;
	int lines;
	int runtime;
	int memory_usage;

void printList(LinkedList *list);// -----------> delete this


void handleInsert(LinkedList *list) {
    // information is placed in new node 
    // node should be inserted alphabetically in linked list 
    // file is alrdy in list? error message should be output

///////////////////////////////////////////////////////////////////////--> INFORMATION COLLECTION
    printf("\n");
	int numchar = printf("Number of characters in file name: ");
    int numofchar = numchar;
    readInputNumber(&numchar);
    
    // need to dynamically allocate memory for strings
    char *filename;
    // +1 accounts for null character
    filename = (char *)malloc(sizeof(char)*numchar + 1);
    *filename = printf("File name: ");
    readInputString(filename,numofchar+1);

    int linenum = printf("Number of lines in CSV file: ");
    readInputNumber(&linenum);

    int runtime = printf("Experiment runtime (ms): ");
    readInputNumber(&runtime);

    int memory_usage = printf("Experiment memory usage(B): ");
    readInputNumber(&memory_usage);

////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////// ----------------------> new node creation
    //////    creates new node

    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode != NULL){
        newNode -> name = filename; 
        newNode -> lines = linenum;
        newNode -> runtime = runtime;
        newNode -> memory_usage = memory_usage;
        newNode -> next = NULL;
    }
///////////////////////////////////////////////////////////////////////////

	Node *current = list-> head;


    ////////////////////////////// -->  if list is empty
      if(current == NULL){
         if (newNode == NULL){
        return; 
    }
	list->head = newNode;
	
	return; 
    }

    /////////////////////////////////// --> if first node is greater than newnode then insert newnode in
    // /////////////////////////////////    front of list

    if (strcmp( filename,current->name) < 0){
        if (newNode == NULL){
        return; 
    }
    newNode -> next = list -> head;
    list -> head = newNode;
	return;
    }

	if(strcmp(filename,current->name) == 0){
		printf("An entry with that file name already exists.");
		return;
	}

    // null part ensures for case when node is inserted at end of list
    while (current -> next != NULL && strcmp(filename,current-> next-> name) > 0){
        current = current -> next;
    }
    
    newNode -> next = current-> next;
    current->next = newNode;
	
	return;
}

void handleDelete(LinkedList *list) {
	// asks user for name of file and then deletes that file's node
	// if no node is found, print an error message
	// make sure memory is freed(for both node and string)

	char *files_name;
    files_name = (char *)malloc(sizeof(char)*STRING_MAX);
    *files_name = printf("Enter file name to delete: ");
	readInputString(files_name,STRING_MAX);

	// empty list
	if(list->head == NULL){
		return;
	}

	// delete head node
	if(strcmp(list->head->name,files_name) == 0){
		Node *savednode = list->head ->next;
		printf("Deleting entry for CSV file <%s>\n",list->head->name);
		free(list->head);
		list->head = savednode;
		return;
	}

	// parse through list and delete
	Node *checker = list -> head;

	while(strcmp(checker->name,files_name) != 0 && checker->next != NULL){
		checker = checker->next;
	}

	if(checker ->next != NULL){
		printf("Deleting entry for CSV file <%s>\n",files_name);

		Node* temp = checker->next;
		checker->next = temp->next;

		free(temp);
		free(files_name);
	}
	else{
		printf("An entry for file <%s> does not exist\n",files_name);
		return; 
	}

return; 
}

void handleSearch(LinkedList *list) {
	double throughput;
	printf("\n");
	char *filesearch;
    filesearch = (char *)malloc(STRING_MAX);
    *filesearch = printf("Enter file name to find: ");
	readInputString(filesearch,STRING_MAX);

	Node *search = list-> head; 

	while(strcmp(filesearch, search-> name) != 0 && search-> next != NULL ){
		search = search -> next;
	}

	if(strcmp(search->name,filesearch) == 0){
		printf("File <%s>\n",search->name);
		printf("Lines: %d\n",search->lines);
		printf("Runtime: %d\n",search->runtime);
		printf("Memory usage: %d\n",search->memory_usage);

		double lines = search-> lines;
		double runtime = search->runtime;
		throughput = (lines)/(runtime);

		printf("Throughput: %.2f\n",throughput);
	}
	else{
		printf("An entry for file <%s> does not exist.\n",filesearch);
		return; 
	}
	return;
}

void handlePrint(LinkedList *list) {
	printf("\n");
	printf("Data entries: \n");
	Node *currents = list-> head;
    double Throughput;

	if(currents == NULL){
		printf("There are no data entries");
		printf("\n");
	}

    while(currents != NULL){
        printf("File <%s>\n",currents->name);
		printf("Lines: %d\n",currents->lines);
		printf("Runtime: %d\n",currents->runtime);
		printf("Memory usage: %d\n",currents->memory_usage);

		double Lines = currents-> lines;
		double Runtime = currents->runtime;
		Throughput = (Lines)/(Runtime);

		printf("File <%.2f>\n",Throughput);
		printf("\n");
        currents = currents -> next;
    }
	
	
}

void handleQuit(LinkedList *list) {
	while(list-> head != NULL){
		Node *savednodeS = list->head ->next;
		printf("Deleting entry for CSV file <%s>",list->head->name);
		free(list->head);
		list->head = savednodeS;
	}

	list-> head = NULL;
	exit(0);
}


/* DO NOT EDIT THE LINES BELOW */
void readInputString(char *str, int length) {
	int i = 0;
	char c;

	while (i < length && (c = getchar()) != '\n') {
		str[i++] = c;
	}

	str[i] = '\0';
}

void readInputNumber(int *number) {
	char buf[STRING_MAX];
	readInputString(buf, STRING_MAX);
	*number = (int)strtol(buf, (char **)NULL, 10);
}

void readInputChar(char *character) {
	char buf[2];
	readInputString(buf, 3);
	*character = buf[0];
}

LinkedList * newList() {
	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	list->head = NULL;
	return list;
}

char getCommand() {
	char command;

	printf("\nSupported commands are:\n");
	printf("  I - Insert\n");
	printf("  D - Delete\n");
	printf("  S - Search\n");
	printf("  P - Print\n");
	printf("  Q - Quit\n");

	printf("\nPlease select a command: ");
	readInputChar(&command);

	while (command != 'I' && command != 'D' && command != 'S' && command != 'P' && command != 'Q') {
		printf("Invalid command <%c>, please select a command: ", command);
		readInputChar(&command);
	}

	return command;
}
/* DO NOT EDIT THE LINES ABOVE */
