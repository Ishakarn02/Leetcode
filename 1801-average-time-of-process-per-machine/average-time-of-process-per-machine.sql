# Write your MySQL query statement below
select machine_id, round(avg(endTime - starttime), 3) as processing_time
from (
    select machine_id, process_id, 
    max(case when activity_type = 'end' then timestamp end) as endTime,
    max(case when activity_type = 'start' then timestamp end) as startTime
    from activity
    group by machine_id, process_id
) as process_times
group by machine_id