min(winequality.red$quality)
max(winequality.red$quality)
mean(winequality.red$quality)

min(winequality.white$quality)
max(winequality.white$quality)
mean(winequality.white$quality)

Качество <- c ( "Название","минимум" ,"максимум",  "среднее")
Красное <- c ( "Красное"min(winequality.red$quality) ,max(winequality.red$quality),  mean(winequality.red$quality))
Белое <- c ( "Белое",min(winequality.white$quality) , max(winequality.white$quality),  mean(winequality.white$quality))

Winequality1 <- data.frame(Красное=Красное,Белое=Белое)
summary(Winequality)
