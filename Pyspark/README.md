![BAIME banner](https://user-images.githubusercontent.com/47600826/73174265-9c3c5e80-4107-11ea-858b-c2c9f5304729.png)

# Pyspark

Hi there,

This repo is about the information I gathered about PySpark. 
You can read all documents from [Apache Spark - Pyspark here](https://spark.apache.org/docs/latest/api/python/pyspark.sql.html#module-pyspark.sql).

## Key take-aways
After watching this YouTube intro from [Josh Rosen](https://www.youtube.com/watch?v=xc7Lc8RA8wE) (tip!!), I learned that: 
- Pyspark improves efficiency through in-memory computing primitives and general computation graphs
- Pyspark improves usability through rich API's in Scala, Python and Java, in an interactive shell
- Pyspark can make your dataset an RDD (Resilient Distributed Dataset) --> immutable, partioned collection of objects by using 
''''df.cache()''''
- Pyspark is built on top of the Java API of Spark
- Pyspark works with Python and not [Jython](https://www.jython.org/), which means that it supports all libraries of Python(!!)
- Pyspark re-uses [Spark's](https://spark.apache.org/) scheduling, broadcast, checkpointing, networking, fault-recovery and [HDFS](https://hadoop.apache.org/docs/r1.2.1/hdfs_design.html) access 
- Pyspark has a small codebase
- Pyspark stores batches of Python objects in one Scala object, this reduces overhead
- Pyspark merges all functions / actions to be taken on the dataset rather than run the steps seperately.

Hope this helps you in learning about PySpark too. 
If you have any tips, let me know via [email](renate@baime.nl)

Kind regards,

Renate van Kempen


![Renate](https://user-images.githubusercontent.com/47600826/73173281-4f578880-4105-11ea-8862-4c54a530e7f4.jpg)