train = function(Hidden, thr3shold) 
{
  plot(x, y, type = "l", col = "green", lwd = 9)
  net = neuralnet(y~x, hidden=Hidden, threshold=thr3shold, learn)
  test = data.frame(x, 0)
  y1 = predict(net, test)
  lines(x, y1)
}

x = seq(from = 0, to = 3.15, by = 0.05)
y = rep(c(1,1,1,1,0,0,0,0), 8)

learn = data.frame(x, y)
library(neuralnet)
par(mfrow = c(2, 2))
train(c(15, 15), 0.01)
train(c(20, 20), 0.005)
train(c(25, 20, 25), 0.001)
train(c(20, 35, 20), 0.0005)
plot(net, show.weights = F)
