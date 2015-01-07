/** CS515 Lab 4
 * File: queue.cpp
 * Name: Joseph Bennett
 * Section: 3
 * Date: 10/04/14
 * Collaboration Declaration: none
 * Lab  Partner: none 
 * Collaboration:  none
 * */

#include "queue.h"

queue::queue(){
	front = 0;
	rear = 0;//Front and rear start at 0
}

//Add a value to the queue
void queue::enqueue(int data){
	item[(rear+front) % MAX_CAP] = data;//the data is equal to the front item added to the size of the array
	rear++;//The rear is incremented because we're adding a new value
}

//Pop the front item out of the queue
int queue::dequeue(){
	int frontItem = item[front];//Save the value of the front item being dequeued
	if ((front + 1) % MAX_CAP != 0)//If the front is not a multiple of 10
		front++;//Increment the front
	else
		front=0;//Front is set to equal 0
	rear--;//Back decreases
	return frontItem;//Return the value dequeued
}

//Display the input to the user
void queue::display(ostream &os){
	for(int i=0; i<rear; i++) //Select all values in the queue
		os<<item[(front + i)% MAX_CAP]<<endl; //Display it to the user as an output stream
}

//Return the size of the queue
int queue::size(){
    return rear; //Size of the queue is equal to the rear
}

//Return a boolean indicating whether the queue is empty
bool queue::empty(){
    return (rear == 0);//If the rear is zero, so is the size of the array
}

//Return a boolean idicating whether or not the queue is full
bool queue::full(){
    return (size() >= MAX_CAP); //Return whether or not the size is equal to the maximum
}
