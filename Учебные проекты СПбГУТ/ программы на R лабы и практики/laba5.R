library(keras)
dir <- 'cats'
datagen <- image_data_generator(
  rescale = 1/255, 
  rotation_range = 30, 
  width_shift_range = 0.4, 
  height_shift_range = 0.7, 
  shear_range = 0.4, 
  zoom_range = 0.7, 
  horizontal_flip = TRUE, 
  vertical_flip = TRUE, 
  fill_mode = "nearest"
)

fnames <- list.files(dir, full.names = TRUE)
img_path <- fnames[[9]].
img <- image_load(img_path,target_size = c(300,300))
img_array <- image_to_array(img)
img_array <- array_reshape (img_array, c(1, 150,150,4))

augmentation_generator <- flow_images_from_data(
  img_array, 
  generator = datagen, 
  batch_size = 3
)

op <- par(mfrow = c(3,4), pty = 's', mar = c(0,0,0,0))
for (i in 1:16){
  batch <- generator_next(augmentation_generator)
  plot(as.rster(batch[1,,,]))
}
