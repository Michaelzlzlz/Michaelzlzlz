library(keras)
library(RBM)
library(tensorflow)

#подготовка обучающей выборки
data<-keras::dataset_fashion_mnist()
list<-list()
for(i in 1:25) list[[i]]<-c(data$train$x[i,1:28,1:28]/255)
trainData<-matrix(unlist(list),nrow = 25,byrow = TRUE)


for(i in 1:25) image(matrix(trainData[i,],nrow=28))


#Подготовка для печати
par(mar=c(1,1,1,1))
par(mfrow=c(3,25))

#Обучение одноуровневой Больцмана
set.seed(25)
mod <- RBM(trainData, n.iter = 1450, n.hidden = 60)

#Реконструкция 25 изображений одноуровневой машины
for (i in 1:25) {
  tryCatch(
  {image(ReconstructRBM(trainData[i,], model=mod)) },
  error=function(cond) {return(NA)})}

# Обучение стека ограниченных машин Больцмана
set.seed(25)
net<-StackRBM(trainData,n.iter=2000,layers=c(30,60,120))

#Реконструкция 25 изображений многоуровневой машины
for (i in 1:25) {
  tryCatch(
  {image(ReconstructRBM(trainData[i,], model=net,layers=3)) },
  error=function(cond) {return(NA)})}

