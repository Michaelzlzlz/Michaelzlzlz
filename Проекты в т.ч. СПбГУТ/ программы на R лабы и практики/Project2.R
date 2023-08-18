set.seed(9)
x <- runif(50,0,8)
y <-2*cos(x) + 8
plot (x, y, pch = 16, cex = 1.5, col = 'green')
learn=data.frame(x,y)

library(neuralnet)
netcos <- neuralnet (y-x,hidden - 4, learn)

set.seed(6)
x <- runif(5000, 0, 8)
y <- 0
test=data.frame(x,y)
yp <- predict(netcos, test)
points(x, yp, col = 'black', pch = '.', cex = 1.5)
plot(netcos)


y1=1/(1+exp(-32.79766*x - 35.59392))
y2=1/(1+exp(-1.54957*x + 7.37296))
y3=1/(1+exp(1.49435*x - 11.54414))
y4=1/(1+exp(1.72479*x - 2.87867))

set.seed(6)
x <- runif(5000,0,8)
plot(x, y2, col="blue")
points(x, y1, col='red')
points(x, y3, col='green')
points(x, y4, col='yellow')

y=y1*(-0.17364)+y2*5.81777+y3*5.43294+y4*5.07481-0.03697
plot(x,y)