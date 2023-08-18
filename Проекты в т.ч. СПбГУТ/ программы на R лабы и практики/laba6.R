library(kohonen)

x <- yeast
df <- data.frame(x)
summary(df)
any(is.na.data.frame(df))
df[is.na.data.frame(df)] <- 0

data(yeast)

yeast.supersom <- supersom(yeast, somgrid(15, 15, "hexagonal"),
                           whatmap = c("cln", "clb", "alpha", "cdc15", "cdc28", "elu"),
                           maxNA.fraction = .6)
obj.classes <- as.integer(yeast$class)
colors <- c("black", "yellow", "green", "blue", "red", "orange")
groups <- 10
plot(yeast.supersom, type="mapping",
     bgcol=rainbow(groups), col = colors[obj.classes],
     pch = obj.classes, main = "yeast data")
legend(x = "bottomleft", col = colors, pch = obj.classes,
       legend = c("cln", "clb", "alpha", "cdc15", "cdc28", "elu"))
