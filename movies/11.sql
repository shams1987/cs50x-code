select movies.title
from people
join movies on stars.movie_id = movies.id
join stars on people.id = stars.person_id
join ratings on movies.id = ratings.movie_id
where name = "Chadwick Boseman"
order by rating desc
limit 5;