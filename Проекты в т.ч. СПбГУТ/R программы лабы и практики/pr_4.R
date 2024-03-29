#5 ����
library(keras)
library(RBM)

# ���������� ��������� �������
dano<-dataset_fashion_mnist()
spisok<-list()
for(k in 1:25) spisok[[k]]<-c(dano$train$x[k,1:28,1:28]/255)
photoData<-matrix(unlist(spisok),nrow = 25,byrow = TRUE)
# ���������� ��������� �� ����� �������
par(mar=c(1,1,1,1))
par(mfrow=c(5,5))
for(j in 1:25) image(matrix(photoData[j,],nrow=28))

# �������� ������������ ������ ���������
set.seed(25)
rbm_l1 <- RBM(photoData, n.iter = 1400, n.hidden = 60)

# ������������� 25 ����������� ������������� ������
for (i in 1:25) {
  tryCatch(
    {image(ReconstructRBM(photoData[i,], model=rbm_l1)) },
    error=function(cond) {return(NA)})}

# �������� ����� ������������ ����� ���������
set.seed(25)
rbm_l3<-StackRBM(photoData,n.iter=1400,layers=c(50,60,140))

# ������������� 25 ����������� �������������� ������
for (j in 1:25) {
  tryCatch(
    {image(ReconstructRBM(photoData[j,], model=rbm_l3,layers=3)) },
    error=function(cond) {return(NA)})}

