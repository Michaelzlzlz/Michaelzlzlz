library(keras)
library(RBM)
library(tensorflow)

#���������� ��������� �������
data<-dataset_fashion_mnist()
list<-list()
for(i in 1:25) list[[i]]<-c(data$train$x[i,1:28,1:28]/255)
photoData<-matrix(unlist(list),nrow = 25,byrow = TRUE)

for(i in 1:25) image(matrix(photoData[i,],nrow=28))

#�������� ������������� ���������
set.seed(25)
mod1 <- RBM(photoData, n.iter = 1450, n.hidden = 60)

#������������� 25 ����������� ������������� ������
for (i in 1:25) {
  tryCatch(
    {image(ReconstructRBM(photoData[i,], model=mod1)) },
    error=function(cond) {return(NA)})}

# �������� ����� ������������ ����� ���������
set.seed(25)
mod3<-StackRBM(photoData,n.iter=1450,layers=c(30,60,120))

#������������� 25 ����������� �������������� ������
for (i in 1:25) {
  tryCatch(
    {image(ReconstructRBM(photoData[i,], model=mod3,layers=3)) },
    error=function(cond) {return(NA)})}
