select distinct player_id,MIN(event_date) AS first_login
from Activity
where event_date IS NOT NULL group by player_id;