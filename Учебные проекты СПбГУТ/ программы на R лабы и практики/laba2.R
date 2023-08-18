library(fpp2)
library(nnet)
scripts <- departures[,4]
n <- length(scripts)
LearnSeq <- matrix(rep(0, (n-12)*13), nrow = n-12, ncol = 13)
for (i in 1:(n-12)) LearnSeq[i, ] <- scripts[i:(12 + i)]
set.seed(55)
Nnet <- nnet(LearnSeq[,1:12], LearnSeq[,13], size = 64, linout = TRUE, rang = 0, maxit = 2000)
prognos <- c(rep(0,12), Nnet$fitted.values)
ggplot(scripts, aes(x)) + geom_line(aes(y=scripts), color="blue", size = 2) + geom_line(aes(y=prognos), color="yellow", size =0.5)
library(NeuralNetTools)
plotnet(Nnet) 
