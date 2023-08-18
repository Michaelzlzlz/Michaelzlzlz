x1<-rep(c(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1))
x2<-rep(c(0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1))
x3<-rep(c(0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1))
x4<-rep(c(0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1))

#операция 4И с инверсией по первому входу
set.seed(1)
data <- c(!(x1)&(x2)&(x3)&(x4))
binary.data = expand.grid(c(0,1), c(0,1), c(0,1), c(0,1))
learn=data.frame(binary.data,data)

library(neuralnet)
neut<-neuralnet(data~.,hidden=3,learn)

set.seed(3)
binary.data = expand.grid(c(0,1), c(0,1), c(0,1), c(0,1))
test=data.frame(binary.data)
Y <- predict(neut,test)
predicted = data.frame(binary.data,Y)
View(predicted)
predicted_bool = predicted
predicted_bool$Y <- as.logical(round(predicted$Y))
View(predicted_bool)
plot(neut)