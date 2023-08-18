library(nnet)
options(max.print = 999999)
data.diagnoz = read.table("C:/laba3/vertebral_column_data/column_3C.dat")
data.diagnoz$V7 = NULL
target = class.ind(c(rep('dh', 60), rep('sl', 150), rep('no', 100)))
set.seed(61)
samp = c(sample(1:60, 45), sample(61:210, 113), sample(211:310, 75))
train.set = data.diagnoz[samp,]
test.set = data.diagnoz[-samp,]
set.seed(90)
net = nnet(train.set, target[samp,], size = 27, maxit = 1000)
net.pred = predict(net, test.set)
table(max.col(target[-samp,]), max.col(net.pred))

