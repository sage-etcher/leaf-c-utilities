const search_elements = [
	{
		label: "hashmap.h header",
		path:  "#!"
	},
	{
		label: "hashMap structure",
		path:  "#!"
	},
	{
		label: "hashMap_new function",
		path:  "#!"
	},
	{
		label: "hashMap_free function",
		path:  "#!"
	},
	{
		label: "hashMap_set function",
		path:  "#!"
	},
	{
		label: "hashMap_lookup function",
		path:  "#!"
	},
	{
		label: "hashMap_lookup_size function",
		path:  "#!"
	},
	{
		label: "hashMap_remove function",
		path:  "#!"
	},
	{
		label: "keyvaluepair.h header",
		path:  "#!"
	},
	{
		label: "keyValuePair structure",
		path:  "#!"
	},
	{
		label: "keyValuePair_new function",
		path:  "#!"
	},
	{
		label: "keyValuePair_free function",
		path:  "#!"
	},
	{
		label: "keyValuePair_get_value function",
		path:  "#!"
	},
	{
		label: "keyValuePair_get_key function",
		path:  "#!"
	},
	{
		label: "keyValuePair_set_value function",
		path:  "#!"
	},
	{
		label: "keyValuePair_set_key function",
		path:  "#!"
	}
];


function add_search_items (element_array) {
	element_array.forEach ((element) => {
		$("#search-content-display").append(`<li><a href="${element.path}">${element.label}</a></li>`);	
	});
}

function refresh_search_content () {
	$("#search-content-display").empty();
}

function get_search_string () {
	return $("#quick-access-search").val();
}

function search_for_elements (list, search_term) {
	let sub_list = [];

	for (let i = list.length - 1; i >= 0; i--) {
		let element = list[i];

		if (element.label.includes(search_term)) {
			sub_list.push(element);
		}
	}	
	
	return sub_list;
}


// quick sort start
function string_compare (s, t) {
	for (let i = 0; i < Math.min(s.length, t.length); i++) {
		if (s[i] == t[i])
			continue;

		return (s[i] < t[i] ? true : false);
	}

	return (s.length <= t.length ? true : false);
}

function partition_elements (list, start, end) {
	const pivot_value = list[end];
	let pivot_index = start;

	for (let i = start; i < end; i++) {
		if (string_compare((list[i].label).toUpperCase(), (pivot_value.label).toUpperCase())) {
			[list[i], list[pivot_index]] = [list[pivot_index], list[i]];

			pivot_index++;
		}
	}
	
	[list[pivot_index], list[end]] = [list[end], list[pivot_index]]
	return pivot_index;
}


function alphabetize_elements (list) {
	// use iterative quicksort to alphabetize the given list of elements 
	let sorted_list = structuredClone(list);
	let stack = [];

	stack.push(0);
	stack.push(sorted_list.length - 1);

	while (stack[stack.length - 1] >= 0) {
		end = stack.pop();
		start = stack.pop();

		pivot_index = partition_elements (sorted_list, start, end);

		if (pivot_index - 1 > start) {
			stack.push(start);
			stack.push(pivot_index - 1);
		}
		
		if (pivot_index + 1 < end) {
			stack.push(pivot_index + 1);
			stack.push(end);
		}
	}

	return sorted_list;
}
// quick sort end


function update_search_contents ()
{
	let search_string = get_search_string();
	let search_results = search_for_elements(search_elements, search_string);
	let search_results_sorted = alphabetize_elements(search_results);

	refresh_search_content();
	add_search_items(search_results_sorted);
}


/* on page load, added contents to the quickaccess section */
$(document).ready(function() {
	update_search_contents();
});

/* update quickaccess contents on search box update */
$('#quick-access-search').on('input', function (e) {
	update_search_contents();
});
