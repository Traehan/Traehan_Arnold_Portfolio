double[] score = new double[5];
int index;
double max;

System.out.println("Enter 5 scores:");
score[0] = keyboard.nextDouble();
max = score[0];

for (index = 1; index < 5; index++){
    score[index] = keyboard.nexDouble();
    if (score[index] > max){
        max = score[index];
    }
}

System.out.println("The highest score is " + max);
System.out.println("the scores are:");

for (index = 0; index < 5; index++){
    System.out.println(score[index] + "differes from max by" + (max - score[index]));
}