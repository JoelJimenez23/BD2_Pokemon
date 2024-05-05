df = read.csv("AppleStore.csv")

names(df)
a = df$track_name
max(nchar(a))
