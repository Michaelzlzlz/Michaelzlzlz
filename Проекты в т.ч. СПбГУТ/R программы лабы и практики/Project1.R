min(winequality.red$quality)
max(winequality.red$quality)
mean(winequality.red$quality)

min(winequality.white$quality)
max(winequality.white$quality)
mean(winequality.white$quality)

�������� <- c ( "��������","�������" ,"��������",  "�������")
������� <- c ( "�������"min(winequality.red$quality) ,max(winequality.red$quality),  mean(winequality.red$quality))
����� <- c ( "�����",min(winequality.white$quality) , max(winequality.white$quality),  mean(winequality.white$quality))

Winequality1 <- data.frame(�������=�������,�����=�����)
summary(Winequality)
