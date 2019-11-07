//file in
using namespace std;

int main(int argc, char **argv)
{
  GenQueue<int> fileIn;
  GenQueue<Student> *studentList = new GenQueue<Student>
  Student s = new Student;

  //file io
  if (argc!=2)
  {
    //not enough args
    cout <<"Expected 2 arguments"<<endl;
    return 0;
  }
  //sufficient arg count
  if stream infile(argv[1]);
  //file cannot be opened
  if (!infile.is_open()){
    cout<<"Cannot open file"<<endl;
    return 0;
  }
  //file can be opened
  //read file into int Queue
  int n;
  while(infile>>n)
  {
    fileIn.insert(n);
  }

  int numWindows = fileIn.remove();

  //read student info until queue isEmpty
  while(!textFile.isEmpty()){
    int arrivalTime = fileIn.remove();
  }

}
//read line 1 - # of windows open
//line 2 - time when students arrive
//3 - how many students - some int x
//3+x - each line is how long the student spends at the window
//3+x+1 - next time
//more students etc

//collect student wait times, and window idle times, then calculate means, medians, etc
