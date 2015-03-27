#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;
typedef struct student Student;
typedef Student* Student_ptr;
typedef struct studentList StudentList;
typedef StudentList* StudentList_ptr;

struct student{
	char* name;
	int id;
	Student_ptr next;
};

struct studentList {
	int count;
	Student_ptr head;
	Student_ptr tail;
};

struct node {
	void* data;
	void* next;
};

StudentList_ptr createList(){
	StudentList_ptr ls = calloc(1,sizeof(StudentList));
	return ls;
}

void addStudent (Student_ptr s,StudentList_ptr l){
	l->tail->next = s;
	l->tail = s;
}

void displayList(StudentList_ptr list){
	printf("head =%p tail =%p count=%d\n",list->head,list->tail,list->count );
}

void displayStudent(Student s){
	if(s.next == NULL)
		printf("%d : %s END\n",s.id,s.name);
	else
		printf("%d : %s next-%p\n",s.id,s.name,s.next );
}

Student_ptr createStudent (int id, char* name, Student_ptr next){
	Student_ptr s = malloc(sizeof(Student));
	int strLength = strlen(name);
	char* str = malloc(strLength+1);
	strcpy(str,name);
	s->name = str;
	s->id = id;
	s->next = next;
	return s;
}

int main(void) {
	Student_ptr s1,s2,new_student;
	StudentList_ptr list;
	Node n1;
	list = createList();

	s2 = createStudent(2,"Sayli",NULL);
	s1 = createStudent(1,"Dolly",s2);
	new_student = createStudent(3,"Naya Bacha",NULL);

	displayStudent(*s1);
	displayStudent(*s2);
	displayStudent(*new_student);

	printf("s1 - %p\n",s1 );
	printf("s2 - %p\n",s2 );
	printf("new - %p\n",new_student );
	
	printf("initial list:\n");
	displayList(list);
	list->head = s1;
	list->tail = s2;
	printf("initialized list:\n");
	displayList(list);

	addStudent(new_student,list);
	printf("updated list:\n");
	displayList(list);

	
	return 0;
}