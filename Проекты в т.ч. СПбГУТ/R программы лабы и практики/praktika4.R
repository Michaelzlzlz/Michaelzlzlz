library(keras)
library(RBM)
library(tensorflow)

#���������� ��������� �������
data<-keras::dataset_fashion_mnist()
list<-list()
for(i in 1:25) list[[i]]<-c(data$train$x[i,1:28,1:28]/255)
trainData<-matrix(unlist(list),nrow = 25,byrow = TRUE)


for(i in 1:25) image(matrix(trainData[i,],nrow=28))


#���������� ��� ������
par(mar=c(1,1,1,1))
par(mfrow=c(3,25))

#�������� ������������� ���������
set.seed(25)
mod <- RBM(trainData, n.iter = 1450, n.hidden = 60)

#������������� 25 ����������� ������������� ������
for (i in 1:25) {
  tryCatch(
  {image(ReconstructRBM(trainData[i,], model=mod)) },
  error=function(cond) {return(NA)})}

# �������� ����� ������������ ����� ���������
set.seed(25)
net<-StackRBM(trainData,n.iter=2000,layers=c(30,60,120))

#������������� 25 ����������� �������������� ������
for (i in 1:25) {
  tryCatch(
  {image(ReconstructRBM(trainData[i,], model=net,layers=3)) },
  error=function(cond) {return(NA)})}

