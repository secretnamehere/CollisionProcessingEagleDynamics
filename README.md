# Interview

Для реализации эффективного поиска столкновений был выбран подход Sweep and Prune. Он хорошо себя показывает, когда сцена меняется практически непрерывно. 
Это используется при сортировке BoundingBox'ов объектов сцены(при плавном перемещении объектов сортировать нужно лишь небольшую их часть, поддерживать сортировку не затратно по времени).
Для оптимизации производился расчет выборочной дисперсии центров объектов и на основании дисперсии сортировка объектов производилась по той или иной оси.
Там, где больше дисперсия меньше вероятность того, что сортировка будет затрагивать больше объектов.
Таким образом, можно говорить о словжности алгоритма O(n*log(n)), но стоит помнить, что большое количество кадров сортировать нужно совсем немного объектов.
Дополнительно был произведен рефакторинг приложения в той степени, чтобы было удобно взаимодействовать на уровне тестового приложения.
При столкновении двух шаров происходит смена цвета обоих для наглядности. 
