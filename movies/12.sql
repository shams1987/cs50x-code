select movies.title
from people
join stars on people.id = stars.person_id
join movies on stars.movie_id = movies.id
where people.name = "Johnny Depp"
intersect
select movies.title
from people
join stars on people.id = stars.person_id
join movies on stars.movie_id = movies.id
where people.name = "Helena Bonham Carter";