因为first_free 指向第一个空闲位置，也就是最后一个 string 的尾后位置。当添加新 string时，应该保存在 first_free指向的位置，然后将first_free推进一个位置，因此后置递增运算恰好符合要求。

如果使用前置递增运算，则是先将 first_free 推进一个位置，然后将新 string 保存在新位置上。显然，这种方法意味着 first_free 指向最后一个string，而非尾后位置，与first_free的设定不吻合。