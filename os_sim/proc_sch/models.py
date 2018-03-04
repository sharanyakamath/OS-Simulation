from django.db import models

# Create your models here.
class Sch_Algo(models.Model):
	arrival_time = models.CharField(max_length=250)
	burst_time= models.CharField(max_length=250)

	def __str__(self):
		return 'AT: ' + self.arrival_time + ' BT: ' + self.burst_time
